#include <string>
#include <vector>

namespace Core
{
	namespace StringFunc
	{
		 std::vector<std::string> Split(std::string str, char splitChar)
		{
			/// <summery>
			/// Split a string by a char
			/// </summery>
			/// <param name="str">The string to split</param>
			/// <param name="splitChar">The char to split the string by</param>
			/// <returns>A vector of strings</returns>

			std::vector<std::string> result;
			std::string currentString = "";

			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == splitChar)
				{
					result.push_back(currentString);
					currentString = "";
				}
				else
				{
					currentString += str[i];
				}
			}

			result.push_back(currentString);

			return result;
		}
	}
}