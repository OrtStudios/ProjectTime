#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using std::string;

namespace Core
{
	class DataFileStructure
	{
	public:
		//*---------//
		//* String //
		//*-------//
		// Set the String Value of a Property (for a given index)
		void SetString(const std::string& value, const size_t itemIndex = 0);

		// Retrieves the String Value of a Property (for a given index) or ""
		const string GetString(const size_t itemIndex = 0) const;

		//*--------------//
		//* Real Number //
		//*------------//
		// Sets the Real Value of a Property (for a given index)
		void SetReal(const double value, const size_t itemIndex = 0);

		// Retrieves the Real Value of a Property (for a given index) or 0.0
		const double GetReal(const size_t itemIndex = 0) const;

		//*----------//
		//* Integer //
		//*--------//
		// Sets the Integer Value of a Property (for a given index)
		void SetInt(const int value, const size_t itemIndex = 0);

		// Retrieves the Integer Value of a Property (for a given index) or 0
		const int32_t GetInt(const size_t itemIndex = 0) const;

		//*--------//
		//* Utils //
		//*------//
		// Returns the number of values a property contains
		size_t GetValueCount() const;

		// Returns a map of all the properties in this node
		const std::vector<std::pair<string, DataFileStructure>>& GetObjects() const;

		DataFileStructure& operator[](const string& name);

		void clear();

		//*---------------//
		//* Write & Read //
		//*-------------//
		bool Write(
            const string&   fileName,
            const string&   indent = "\t",
            const char      listSeparator = ','
        );

		bool Read(
			const string& fileName,
			const char    listSeparator = ','
        );

	private:
		// The "list of strings" that make up a property value
		std::vector<string> m_contentVector;

		std::vector<std::pair<string, DataFileStructure>> m_objectsVector;
		std::unordered_map<string, size_t>       m_objectsMap;

	protected:
		// Used to identify if a property is a comment or not
		bool m_isComment = false;
	};
}