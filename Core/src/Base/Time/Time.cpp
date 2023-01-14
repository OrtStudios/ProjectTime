#include "Time.h"
#include "src/Base/Logger.h"
#include "src/Base/Types/StringFunc.h"

#include <string>
#include <format>

using std::string;

namespace Core
{
	namespace Time
	{
		std::string PhraseFormat(std::string UserFormat, bool TimeInTheDay)
		{
			/// <summary>
			/// convert from user friendly format to the format to be used in the log time
			/// </summary>
			/// <param name="UserFormat"> the format of the time </param>
			/// <param name="TimeInTheDay"> if the time is in the day or not </param>
			/// <returns> the format to be used in the log time </returns>
			if (TimeInTheDay)
			{
				if (UserFormat == "M.D")
				{
					Logger::Log("format: %m.%d.%Y %H:%M:%S", Logger::LogType::INFO);
					return "%m.%d.%Y %H:%M:%S";
				}
				else
				{
					Logger::Log("format: %d.%m.%Y %H:%M:%S", Logger::LogType::INFO);
					return "%d.%m.%Y %H:%M:%S";
				}
			}
			else
			{
				if (UserFormat == "M.D")
				{
					Logger::Log("format: %m.%d.%Y", Logger::LogType::INFO);
					return "%m.%d.%Y";
				}
				else
				{
					Logger::Log("format: %d.%m.%Y", Logger::LogType::INFO);
					return "%d.%m.%Y";
				}
			}
		}

		std::string GetTime(std::string UserFormat, bool TimeInTheDay)
		{
			/// <summary>
			/// get the time in the given format
			/// </summary>
			/// <param name="UserFormat"> the format of the time </param>
			/// <param name="TimeInTheDay"> if the time is in the day or not </param>
			/// <returns> the time in the given format </returns>
			std::time_t now = std::time(NULL);
			Logger::Log("Getting the time", Logger::LogType::DEBUG);

			// convert to local time
			std::tm* ptm = std::localtime(&now);
			Logger::Log("Converting to local time", Logger::LogType::DEBUG);

			// the buffer
			char buffer[32];
			Logger::Log("Creating the buffer", Logger::LogType::DEBUG);

			// phrase the format
			std::string format = PhraseFormat(UserFormat, TimeInTheDay);
			Logger::Log("Phrasing the format", Logger::LogType::DEBUG);

			// convert to string to be stored in the buffer
			std::strftime(buffer, 32, format.c_str(), ptm);
			Logger::Log("Converting to string", Logger::LogType::DEBUG);

			return buffer;
		}

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
		
		// Time class
		Time::Time()
		{
			// Get the current time
			time_t currentTime = time(0);

			// Convert the current time to a tm struct
			tm* localTime = localtime(&currentTime);

			// Set the time
			hours = localTime->tm_hour;
			minutes = localTime->tm_min;
			seconds = localTime->tm_sec;
		}

		Time::Time(int h, int m, int s)
		{
			setTime(h, m, s);
		}

		int Time::getHours()
		{
			return hours;
		}

		int Time::getMinutes()
		{
			return minutes;
		}

		int Time::getSeconds()
		{
			return seconds;
		}

		void Time::setHours(int h)
		{
			hours = h;
		}

		void Time::setMinutes(int m)
		{
			minutes = m;
		}

		void Time::setSeconds(int s)
		{
			seconds = s;
		}

		void Time::setTime(int h, int m, int s)
		{
			setHours(h);
			setMinutes(m);
			setSeconds(s);
		}

		void Time::logTime()
		{
			Logger::Log(
				std::format(
					"Time: {}:{}:{}",
					getHours(),
					getMinutes(),
					getSeconds()
				),
				Logger::LogType::INFO
			);
		}
	}
}