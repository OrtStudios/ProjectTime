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

	int Logger::nthOccurrence(const string str, const string findMe, int nth)
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

			//get the month 
			pos = nthOccurrence(theTimeNow, " ", 1);

			string mounthName = theTimeNow.substr(pos + 1, 3);

			// get the mounth number from the map
			string mounthNumber = m_months.at(mounthName);

			//erase the month name
			theTimeNow.erase(pos, 3);

			// remove the day name from the start of the string
			theTimeNow.erase(0, 4);

			// put the mounth number at the start of the string
			theTimeNow = mounthNumber + theTimeNow;

			// if the mounth is suposed to be in the format D.M change the string
			if (m_dateFormat == "D.M")
			{
				// change the pos to the dot between the day and the mounth
				int pos = nthOccurrence(theTimeNow, ".", 1);

				// get the day number
				string dayNumber = theTimeNow.substr(pos - 2, 2);

				std::cout << "dayNumber: " << dayNumber << std::endl;

				// erase the space in the dayNumber if there is
				for (int i = 0; i < dayNumber.size(); i++)
					if (dayNumber[i] == ' ' || dayNumber[i] == '.')
						dayNumber.erase(i, 1);

				// convert the number to int
				int dayNumberInt = std::stoi(dayNumber);
				int mounthNumberInt = std::stoi(mounthNumber);

				std::cout << dayNumberInt << std::endl;

				// erase the day and the mounth
				if (dayNumberInt < 10 && mounthNumberInt < 10)
				{
					theTimeNow.erase(0, 3);
				}
				else if ((dayNumberInt < 10 && mounthNumberInt > 10) || (dayNumberInt > 10 && mounthNumberInt < 10))
				{
					theTimeNow.erase(0, 4);
				}
				else
					theTimeNow.erase(0, 5);

				// add the day and the mounth with a dot between them in the start of the string
				theTimeNow = dayNumber + "." + mounthNumber + theTimeNow;
			}

			// Log the message to the console
			if (m_logToConsole)
				std::cout << std::format(
					"\x1B[{}m{} >> {}\033[0m\t\t", m_logColors.at(level), theTimeNow, message
				) << std::endl;

			// Log the message to the log file
			if (m_logToFile)
				if (m_logFile.is_open())
					m_logFile << theTimeNow << " >> " << message << std::endl;

			return;
		}

		//* Log File
		void Logger::SetLogFile(const string directoryPath)
		{
			m_logDirectoryPath = directoryPath;

			// Get the time
			auto timeNow = std::chrono::system_clock::now();
			std::time_t timeInTimeTformat = std::chrono::system_clock::to_time_t(timeNow);
			// convert the time into a string
			string theTimeNow = std::ctime(&timeInTimeTformat);

			//File Name Format: <LogDirectoryPath>/ProjectTimeLog_<Time>.log
			// Time = Month / Day
			theTimeNow.erase(nthOccurrence(theTimeNow, " ", 4));
			theTimeNow.erase(0, theTimeNow.find_first_of(" ") + 1);
			theTimeNow.erase(theTimeNow.find_first_of(" "), 1);
			theTimeNow.replace(theTimeNow.find(" "), 1, ".");

			// Set the file name
			m_logFileName = "/ProjectTimeLog_" + theTimeNow + ".log";

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

		//* Log To Console or Not
		void Logger::SetLogToConsole(bool logToConsole)
		{
			m_logToConsole = logToConsole;
		}

		// Log To File or Not
		void Logger::SetLogToFile(bool logToFile)
		{
			m_logToFile = logToFile;
		}
}