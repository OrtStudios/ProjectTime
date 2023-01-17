#include "DataFileStructure.h"

#include <fstream>
#include <functional>
#include <stack>

namespace Core
{
    void DataFileStructure::SetString(const std::string &value, const size_t itemIndex)
    {
		if (itemIndex >= m_contentVector.size())
			m_contentVector.resize(itemIndex + 1);

		m_contentVector[itemIndex] = value;
	}

    const string DataFileStructure::GetString(const size_t itemIndex) const
    {
		if (itemIndex >= m_contentVector.size())
			return "";
		else
			return m_contentVector[itemIndex];
	}

    void DataFileStructure::SetReal(const double value, const size_t itemIndex)
    {
		SetString(std::to_string(value), itemIndex);
	}


    const double DataFileStructure::GetReal(const size_t itemIndex) const
    {
		return std::atof(GetString(itemIndex).c_str());
	}

    void DataFileStructure::SetInt(const int value, const size_t itemIndex)
    {
		SetString(std::to_string(value), itemIndex);
	}

    const int32_t DataFileStructure::GetInt(const size_t itemIndex) const
    {
		return std::atoi(GetString(itemIndex).c_str());
	}

    size_t DataFileStructure::GetValueCount() const
    {
		return m_contentVector.size();
	}

    const std::vector<std::pair<string, DataFileStructure>> &DataFileStructure::GetObjects() const
    {
		return m_objectsVector;
	}

    DataFileStructure& DataFileStructure::operator[](const string& name)
	{
		// Check if this "node"'s map already contains an object with this name...
		if (m_objectsMap.contains(name) == 0)
		{
			// ...it doesn't! So create this object in the map. First get a vector id
			// and link it with the name in the unordered_map.
			m_objectsMap[name] = m_objectsVector.size();

			// then creating the new, blank object in the vector of objects.
			m_objectsVector.push_back({ name, DataFileStructure() });
		}

		// ...it exists! so return the object, by getting its index from the map, and using the
		// index to look up a vector element.
		return m_objectsVector[m_objectsMap[name]].second;
	}

    void DataFileStructure::clear()
    {
		m_contentVector.clear();
		m_objectsVector.clear();
		m_objectsMap.clear();
    }

    // Writes a "DataFile" node (and all of its child nodes and properties) recursively to a file
	bool DataFileStructure::Write(
		const string&   fileName,
		const string&   indent,
		const char      listSeparator
	)
	{
		// Cache seperator string for convenience
		string listSeparatorString = string(1, listSeparator) + " ";

		// Cache indentation level
		size_t indentCount = 0;

		// Fully specified lambda, because this lambda is recursive.
		std::function<void(const DataFileStructure&, std::ofstream&)> write = [&](
			const DataFileStructure& node,
			std::ofstream& file
		)
		{
			// Lambda creates string given indentation preferences
			auto indentCalculator = [&](const string& str, const size_t count)
			{
				string result;
				for (size_t n = 0; n < count; n++) result += str;
				return result;
			};


			// Iterate through each property in this node
			for (auto const& property : node.m_objectsVector)
			{
				// Does property contain any sub objects?
				if (property.second.m_objectsVector.empty())
				{
					file << indentCalculator(indent, indentCount) << property.first << (
						property.second.m_isComment 
							? "" 
							: " = "
					);

					size_t ItemsCount = property.second.GetValueCount();
					for (size_t i = 0; i < property.second.GetValueCount(); ++i)
					{
						// If the Value being written(in string form) contains the separation
						// character, then the value must be written inside quotes.
						// Note, that if the Value is the last of a list of Values for a property,
						// it is not suffixed with the separator.
						size_t x = property.second.GetString(i).find_first_of(listSeparator);

						if (x != std::string::npos)
						{
							// Value contains separator, so write it inside quotes
							file << "\"" << property.second.GetString(i) << "\"" << (
								(ItemsCount > 1) 
									? listSeparatorString 
									: ""
							);
						}
						else
						{
							// Value does not contain separator, so write it as is
							file << property.second.GetString(i) << (
								(ItemsCount > 1) 
									? listSeparatorString 
									: ""
							);
						}

						ItemsCount--;
					}

					// Property written, move to the next line
					file << "\n";
				}
				else
				{
					// Yes, this property has sub properties, so it's a node
					// Force a new line, and write the node's name
					file << "\n" << indentCalculator(indent, indentCount) << property.first << "\n";

					// Open braces, and increase indentation level
					file << indentCalculator(indent, indentCount) << "{\n";
					indentCount++;

					// Recursively write the node's sub properties
					write(property.second, file);

					// Node written -> close braces
					file << indentCalculator(indent, indentCount) << "}\n\n";
				}
			}

			// We've finished writing out a node, regardless of the state ->
			// decrease indentation level, unless we're at the root node
			if (indentCount > 0) indentCount--;
		};

		std::ofstream file(fileName);
		if (file.is_open())
		{
            write(*this, file);
			return true;
		}

		return false;
	}

    bool DataFileStructure::Read(
		const string& fileName,
		const char    listSeparator
	)
	{
		// Open the file
		std::ifstream file(fileName);
		if (file.is_open())
		{
			// These variables are outside of the read loop, as we will
			// need to refer to previous iteration values in the current conditions
			string propertyName  = "";
			string propertyValue = "";

			std::stack<std::reference_wrapper<DataFileStructure>> nodeStack;
			nodeStack.push(*this);

			// Read the file line by line and parse it
			while (!file.eof())
			{
				// Read line
				string line;
				std::getline(file, line);

				// This little lambda removes whitespace from
				// the beginning and end of a string
				auto trim = [](string& str)
				{
					str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
					str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
				};

				trim(line);

				// If line has content
				if (!line.empty())
				{
					if (line[0] == '/' && line[1] == '/')
					{
						// Line is a comment, so ignore it
						DataFileStructure comment;
						comment.m_isComment = true;
						nodeStack.top().get().m_objectsVector.push_back({ line, comment });
					}
					else
					{
						// ...it is not a whitespace line, so Firstly, we find if the line
							// contains an assignment. If it does, then it is a property...
						size_t equalSignIndex = line.find_first_of('=');
						if (equalSignIndex != string::npos)
						{
							// ...so split up the property into a name and a value

								// Extract the property name, which is all the characters up to
								// the first assignment, trim any whitespace, and store it
							propertyName = line.substr(0, equalSignIndex);
							trim(propertyName);

							// Extract the property value, which is all the characters after
							// the first assignment, trim any whitespace, and store it
							propertyValue = line.substr(equalSignIndex + 1, line.size());
							trim(propertyValue);

							// The value may be in a list form(a, b, c, d...) and some
								// elements may exist in quotes(a, b, c, "d, e", f...), so we need to
								// parse it character by character and extract the elements
							bool inQuotes = false;
							string token;
							size_t tokenCount = 0;

							for (const auto c : propertyValue)
							{
								// Is this character a quote?
								if (c == '\"')
								{
									// Yes, so toggle the inQuotes flag
									inQuotes = !inQuotes;
								}
								else
								{
									// No, so proceed with creating a token. If we are in quotes,
									// then just append characters until we exit the quotes.
									if (inQuotes)
										token.append(1, c);
									else
									{
										// Is the character a list separator?
										if (c == listSeparator)
										{
											// Yes, so trim the token and add it to the list
											trim(token);
											nodeStack.top().get()[propertyName].SetString(token, tokenCount);

											// Reset the token and increment the token count
											token.clear();
											tokenCount++;
										}
										else
										{
											// No, so just append the character to the token
											token.append(1, c);
										}
									}
								}
							}

							// Any residual characters at this point are part of the last token
							if (!token.empty())
							{
								// Trim the token and add it to the list
								trim(token);
								nodeStack.top().get()[propertyName].SetString(token, tokenCount);
							}
						}
						else // No '='
						{
							// ...but if it is not a property, then it must be a node. So we
								// check if the line is an opening node...
							if (line[0] == '{')
							{
								// ...if it is, then we push a new node onto the stack
								nodeStack.push(nodeStack.top().get()[propertyName]);
							}
							else
							{
								if (line[0] == '}')
								{
									// ...if it is not, then it must be a closing node. So we pop
										// the top node off the stack
									nodeStack.pop();
								}
								else
								{
									// Line is a property with no assignment. Who knows whether this is useful
									// but we can simply add it as a valueless property...
									propertyName = line;
									// ...actually it is useful, as valueless properties are typically
									// going to be the names of new DataFile nodes on the next iteration
								}
							}
						}
					}
				}
			}

			// Close and exit
			file.close();
			return true;
		}
		else 
			return false;
	}
}