#include "pch.h"

#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <format>
#include <map>

#include "Logger.h"

using std::string;

namespace Core
{
	const std::map<string, string> m_months = {
			{ "Jan", "1"  },
			{ "Feb", "2"  },
			{ "Mar", "3"  },
			{ "Apr", "4"  },
			{ "May", "5"  },
			{ "Jun", "6"  },
			{ "Jul", "7"  },
			{ "Aug", "8"  },
			{ "Sep", "9"  },
			{ "Oct", "10" },
			{ "Nov", "11" },
			{ "Dec", "12" }
	};
	const std::map<Logger::LogType, int> m_logColors = {
		{ Logger::LOG_TYPE_DEBUG,   90 },
		{ Logger::LOG_TYPE_INFO,    94 },
		{ Logger::LOG_TYPE_WARNING, 33 },
		{ Logger::LOG_TYPE_ERROR,   91 },
		{ Logger::LOG_TYPE_FATAL,   31 },
		{ Logger::LOG_TYPE_MASTER,  92 }
	};

	size_t Logger::nthOccurrence(const string str, const string findMe, int nth)
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

		//* Main Log Function
		void Logger::Log(const string message, Logger::LogType level)
		{
			// Check if the level is lower than the current log level
			if (level < m_logLevel)
				return;

			// Get the time
			string theTime = m_GetTheTimeNow(m_dateFormat, true);

			// Log the message to the console
			if (m_logToConsole)
				std::cout << std::format(
					"\x1B[{}m{} >> {}\033[0m\t\t", m_logColors.at(level), theTime, message
				) << std::endl;

			// Log the message to the log file
			if (m_logToFile)
				if (m_logFile.is_open())
					m_logFile << theTime << " >> " << message << std::endl;

			return;
		}

		//* Log File
		void Logger::SetLogFile(const string directoryPath)
		{
			m_logDirectoryPath = directoryPath;

			// Get the time
			string theTime = m_GetTheTimeNow(m_dateFormat, false);

			// Set the file name
			m_logFileName = "/ProjectTimeLog_" + theTime + ".log";

			// save the path
			m_FullPath = m_logDirectoryPath + m_logFileName;

			// Open the file
			m_logFile.open(m_logDirectoryPath + m_logFileName);

			return;
		}


		string Logger::GetLogFilePath()
		{
			return std::format("{}\\{}", m_logDirectoryPath, m_logFileName);
		}

		void Logger::CloseLogFile()
		{
			// save the log file and closes it
			m_logFile.close();
		}

		void Logger::SaveLogFile()
		{
			m_logFile.close();
			m_logFile.open(m_FullPath);
		}

		//* Log Level
		void Logger::SetLogLevel(Logger::LogType level)
		{
			m_logLevel = level;
		}

		Logger::LogType Logger::GetLogLevel()
		{
			return m_logLevel;
		}

		bool Logger::IsLogToFile()
		{
			return m_logToFile;
		}

		//* Log To Console or Not
		void Logger::SetLogToConsole(bool logToConsole)
		{
			m_logToConsole = logToConsole;
		}

		//* Log To File or Not
		void Logger::SetLogToFile(bool logToFile)
		{
			m_logToFile = logToFile;
		}

		//////////////////////////////////
		//* get the time
		string Logger::m_GetTheTimeNow(string Userformat, bool TimeInTheDay)
		{
			// get the time now
			std::time_t now = std::time(NULL);

			// convert to local time
			std::tm* ptm = std::localtime(&now);

			// the buffer
			char buffer[32];

			// perase the format
			string format = m_PeraseFormat(Userformat, TimeInTheDay);

			// convert to string to be stored in the buffer
			std::strftime(buffer, 32, format.c_str(), ptm);

			return buffer;
		}

		//* convert from user freindly format to the format to be used in the log time
		string Logger::m_PeraseFormat(std::string Userformat, bool TimeInTheDay)
		{
			if (TimeInTheDay)
			{
				if (Userformat == "M.D")
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
				if (Userformat == "M.D")
				{
					return "%m.%d.%Y";
				}
				else
				{
					return "%d.%m.%Y";
				}
			}
		}
}