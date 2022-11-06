#include "Time.h"
#include "src/Base/Logger.h"
#include "src/Base/Types/StringFunc.h"

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
			/// <summary>
			/// Get the date as a string
			/// </summary>
			/// <returns> The date as a string </returns>
			if (m_format == "M.D")
			{
				Logger::Log("format: %m.%d.%Y", Logger::LogType::INFO);
				return std::to_string(m_month) + "." + std::to_string(m_day) + "." + std::to_string(m_year);
			}
			else
			{
				Logger::Log("format: %d.%m.%Y", Logger::LogType::INFO);
				return std::to_string(m_day) + "." + std::to_string(m_month) + "." + std::to_string(m_year);
			}
		}

		string Date::GetFormat()
		{
			/// <summary>
			/// Get the date format
			/// </summary>
			/// <returns> The date format </returns>
			return m_format;
		}

		void Date::SetDate(std::string DateString)
		{
			/// <summary>
			/// Set the date
			/// </summary>
			/// <param name="DateString"> The date as a string </param>

			// Split the date string
			std::vector<std::string> dateParts = StringFunc::Split(DateString, '.');

			// Set the date
			m_year = std::stoi(dateParts[0]);
			m_month = std::stoi(dateParts[1]);
			m_day = std::stoi(dateParts[2]);
		}
		
		void Date::SetFormat(std::string Format)
		{
			/// <summary>
			/// Set the date format
			/// </summary>
			/// <param name="Format"> The date format </param>
			m_format = Format;
		}
	}
}