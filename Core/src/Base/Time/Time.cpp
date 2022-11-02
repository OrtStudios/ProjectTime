#include "Time.h"
#include "src/Base/Logger.h"
#include "src/Base/String/StringFunc.h"

#include <string>

using std::string;

namespace Core
{
	namespace Time
	{
		Date::Date()
		{
			// Get the current time
			time_t currentTime = time(0);

			// Convert the current time to a tm struct
			tm* localTime = localtime(&currentTime);

			// Set the date
			m_year = localTime->tm_year + 1900;
			m_month = localTime->tm_mon + 1;
			m_day = localTime->tm_mday;
		}

		Date::Date(std::string DateString)
		{
			// Split the date string
			std::vector<std::string> dateParts = StringFunc::Split(DateString, '.');

			// Set the date
			m_year = std::stoi(dateParts[0]);
			m_month = std::stoi(dateParts[1]);
			m_day = std::stoi(dateParts[2]);
		}

		Date::~Date() {}

		string Date::GetDate()
		{
			// Create the date string
			string dateString = std::to_string(m_year) + "." + std::to_string(m_month) + "." + std::to_string(m_day);

			// Return the date string
			return dateString;
		}

		void Date::SetDate(std::string DateString)
		{
			// Split the date string
			std::vector<std::string> dateParts = StringFunc::Split(DateString, '.');

			// Set the date
			m_year = std::stoi(dateParts[0]);
			m_month = std::stoi(dateParts[1]);
			m_day = std::stoi(dateParts[2]);
		}
	}
}