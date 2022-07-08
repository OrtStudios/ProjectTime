#include "pch.h"

#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <format>
#include <map>

#include "Logger.h"
#include "File Managment/Basic_File.h"

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
		{ Logger::DEBUG,   90 },
		{ Logger::INFO,    94 },
		{ Logger::WARNING, 33 },
		{ Logger::ERROR,   91 },
		{ Logger::FATAL,   31 },
		{ Logger::MASTER,  92 }
	};

	//* Main Log Function
	void Logger::Log(const string message, Logger::LogType level)
	{
		/// <summary>
		/// log message to the console and to the log file
		/// </summary>
		/// <param name="message">message to log</param>
		/// <param name="level">the log level of the message</param>
		
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
			if (m_logFile.IsOpen())
				m_logFile.Write(
					std::format(
						"{} >> {}\n", theTime, message
					)
				);
			else
			{
				m_logFile.Open();
				m_logFile.Write(
					std::format(
						"{} >> {}\n", theTime, message
					)
				);
			}

		return;
	}

	//* Log File
	void Logger::SetLogFile(const string directoryPath)
	{
		/// <summary>
		/// set the log file to the given directory path
		/// </summary>
		/// <param name="directoryPath"> path to the log file directory </param>
		// Get the time
		string theTime = m_GetTheTimeNow(m_dateFormat, false);

		// Create the file
		string path = directoryPath + "/ProjectTimeLog_" + theTime + ".log";
		
		m_logFile = File(directoryPath + "/ProjectTimeLog_" + theTime + ".log", "a");

	}


	string Logger::GetLogFilePath()
	{
		return m_logFile.GetPath();
	}

	bool Logger::CloseLogFile()
	{
		/// <summary>
		/// close the log file
		/// </summary>
		return m_logFile.Close();
	}

	bool Logger::SaveLogFile()
	{
		/// <summary>
		/// save the log file
		/// </summary>
		m_logFile.Save();
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
	string Logger::m_GetTheTimeNow(string UserFormat, bool TimeInTheDay)
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
		string format = m_PhraseFormat(UserFormat, TimeInTheDay);

		// convert to string to be stored in the buffer
		std::strftime(buffer, 32, format.c_str(), ptm);

		return buffer;
	}

	//* convert from user friendly format to the format to be used in the log time
	string Logger::m_PhraseFormat(std::string UserFormat, bool TimeInTheDay)
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
}