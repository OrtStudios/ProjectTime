#pragma once

#include <chrono>
#include <string>

namespace Core
{
	namespace Time
	{
		//* convert from user friendly format to the format to be used in the log time
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

		class Date
		{
		public:
			Date();
			Date(std::string DateString);
			~Date();

			std::string GetDate();
			std::string GetFormat();

			void SetDate(std::string DateString);
			void SetFormat(std::string Format);
			
		private:
			int m_year;
			int m_month;
			int m_day;
			std::string m_format;
		};
	}
}