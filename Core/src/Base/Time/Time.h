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
					return "%m.%d.%Y %H:%M:%S";
				}
				else
				{
					return "%d.%m.%Y %H:%M:%S";
				}
			}
			else
			{
				if (UserFormat == "M.D")
				{
					return "%m.%d.%Y";
				}
				else
				{
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

			// convert to local time
			std::tm* ptm = std::localtime(&now);

			// the buffer
			char buffer[32];

			// phrase the format
			std::string format = PhraseFormat(UserFormat, TimeInTheDay);

			// convert to string to be stored in the buffer
			std::strftime(buffer, 32, format.c_str(), ptm);

			return buffer;
		}
	}
}