#pragma once

#include "src/Logger.h"

#include <chrono>
#include <string>

namespace Core
{
	namespace Time
	{
		//* convert from user friendly format to the format to be used in the log time
		std::string PhraseFormat(std::string UserFormat, bool TimeInTheDay);

		std::string GetTime(std::string UserFormat, bool TimeInTheDay);

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

		class Time
		{
		public:
			//constructors
			Time();
			Time(int h, int m, int s);

			//getters and setters
			int getHours();
			int getMinutes();
			int getSeconds();
			void setHours(int h);
			void setMinutes(int m);
			void setSeconds(int s);
			void setTime(int h, int m, int s);

			//utility functions
			void logTime();

		private:
			int hours;
			int minutes;
			int seconds;
		};
	}
}