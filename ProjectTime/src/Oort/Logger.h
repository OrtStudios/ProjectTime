#pragma once

#include <string>
#include <chrono>
#include <fstream>
#include <format>
#include <map>

#define string std::string

namespace Oort
{
	class m_Logger
	{
	private:
		int nthOccurrence(const string str, const string findMe, int nth)
		{
			size_t  pos = 0;
			int     cnt = 0;

			while (cnt != nth)
			{
				pos += 1;
				pos = str.find(findMe, pos);
				if (pos == string::npos)
					return -1;
				cnt++;
			}
			return pos;
		}
		
	public:
		enum LogType
		{
			LOG_TYPE_DEBUG   = 0,
			LOG_TYPE_INFO    = 1,
			LOG_TYPE_WARNING = 2,
			LOG_TYPE_ERROR   = 3,
			LOG_TYPE_FATAL   = 4,
			LOG_TYPE_MASTER  = 5
		};
		
		//* Main Log Function
		void Log(const string message, LogType level)
		{
			// Check if the level is lower than the current log level
			if (level < m_logLevel)
				return;

			// Get the time
			auto timeNow = std::chrono::system_clock::now();
			std::time_t timeInTimeTformat = std::chrono::system_clock::to_time_t(timeNow);
			// convert the time into a string
			string theTimeNow = std::ctime(&timeInTimeTformat);
			
			// remove the /n at the end of the string and the first 3 characters
			theTimeNow.erase(theTimeNow.end() - 1);

			// remove the second space between the month and the day
			int pos = nthOccurrence(theTimeNow, " ", 2);
			theTimeNow.erase(pos, 1);
			theTimeNow.replace(pos, 1, ".");

			// replace the month name with the month number
			pos = nthOccurrence(theTimeNow, " ", 1);			
			
			string mounthName = theTimeNow.substr(pos + 1, 3);
			string mounthNumber = m_monthNames.find(mounthName)->second;
			
			
			theTimeNow.replace(pos, 3, mounthNumber);
			
			
			// remove the day name from the start of the string
			theTimeNow.erase(0, 4);

			int color = 90;
			
			// Log the message to the console
			if (m_logToConsole)
				std::cout << std::format("\x1B[{}m{} >> {}\033[0m\t\t", color, theTimeNow, message) << std::endl;

			// Log the message to the log file
			if (m_logToFile)
				if (m_logFile.is_open())
					m_logFile << theTimeNow << " >> " << message << std::endl;

			return;
		}

		//* Log File
		void SetLogFile(const string directoryPath)
		{
			m_logDirectoryPath = directoryPath;

			// Get the time
			auto timeNow = std::chrono::system_clock::now();
			std::time_t timeInTimeTformat = std::chrono::system_clock::to_time_t(timeNow);
			// convert the time into a string
			string theTimeNow = std::ctime(&timeInTimeTformat);
			
			//File Name Format: <LogDirectoryPath>/ProjectTimeLog_<Time>.log
			// Time = Mounth / Day
			theTimeNow.erase(nthOccurrence(theTimeNow, " ", 4));
			theTimeNow.erase(0, theTimeNow.find_first_of(" ") + 1);
			theTimeNow.erase(theTimeNow.find_first_of(" "), 1);
			theTimeNow.replace(theTimeNow.find(" "), 1, ".");

			// Set the file name
			m_logFileName = "/ProjectTimeLog_" + theTimeNow + ".log";
			
			// Open the file
			m_logFile.open(m_logDirectoryPath + m_logFileName);

			return;
		}

		
		string GetLogFilePath()
		{
			return std::format("{}\\{}", m_logDirectoryPath, m_logFileName);
		}
		
		//* Log Level
		void SetLogLevel(LogType level)
		{
			m_logLevel = level;
		}
		
		LogType GetLogLevel()
		{
			return m_logLevel;
		}

		//* Log To Console or Not
		void SetLogToConsole(bool logToConsole)
		{
			m_logToConsole = logToConsole;
		}
		
		// Log To File or Not
		void SetLogToFile(bool logToFile)
		{
			m_logToFile = logToFile;
		}
	
	private:
		string m_logDirectoryPath = "";
		string m_logFileName      = "";
		LogType m_logLevel        = LOG_TYPE_WARNING;
		bool m_logToConsole       = true;
		bool m_logToFile          = false;
		std::ofstream m_logFile;
		int debugColor = 90;

		std::map<string, int> m_months = {
			{ "Jan", 1 },
			{ "Feb", 2 },
			{ "Mar", 3 },
			{ "Apr", 4 },
			{ "May", 5 },
			{ "Jun", 6 },
			{ "Jul", 7 },
			{ "Aug", 8 },
			{ "Sep", 9 },
			{ "Oct", 10 },
			{ "Nov", 11 },
			{ "Dec", 12 }
		};
	};
}

Oort::m_Logger Logger = Oort::m_Logger();