#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <format>
#include <map>

#include "rang.hpp"

#include "Logger.h"
#include "src/Base/FileManagment/Basic_File.h"

using std::string;

namespace Core
{
	Core::File* loggerLogFile;
	
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
	const std::map<Logger::LogType, rang::fg> m_logColors = {
		{ Logger::DEBUG,   rang::fg::gray   },
		{ Logger::INFO,    rang::fg::blue   },
		{ Logger::WARNING, rang::fg::yellow },
		{ Logger::_ERROR,  rang::fg::redB   },
		{ Logger::FATAL,   rang::fg::red    },
		{ Logger::MASTER,  rang::fg::green  }
	};
	
	const std::map<Logger::LogType, string> m_logTypeString =
	{
		{ Logger::DEBUG,   "Debug"   },
		{ Logger::INFO,    "Info"    },
		{ Logger::WARNING, "Warning" },
		{ Logger::_ERROR,  "Error"   },
		{ Logger::FATAL,   "Fatal"   },
		{ Logger::MASTER,  "Master"  }
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

		string type = m_logTypeString.at(level);

		// Get the time
		string theTime = m_GetTheTimeNow(m_dateFormat, true);

		// Log the message to the console
		if (m_logToConsole)
			std::cout << m_logColors.at(level) << std::format(
				"{}: {} >> {}", type, theTime, message
			) << rang::style::reset << std::endl;

		// Log the message to the log file
		if (m_logToFile)
			if (loggerLogFile->IsOpen())
				loggerLogFile->Write(
					std::format(
						"{}: {} >> {}\n", type, theTime, message
					)
				);
			else
			{
				loggerLogFile->Open();
				loggerLogFile->Write(
					std::format(
						"{}: {} >> {}\n", type, theTime, message
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
		
		Core::loggerLogFile = new File(directoryPath + "/ProjectTimeLog_" + theTime + ".log");

	}


	string Logger::GetLogFilePath()
	{
		return loggerLogFile->GetPath();
	}

	bool Logger::CloseLogFile()
	{
		/// <summary>
		/// close the log file
		/// </summary>
		return loggerLogFile->Close();
	}

	bool Logger::SaveLogFile()
	{
		/// <summary>
		/// save the log file
		/// </summary>
		return loggerLogFile->Save();
	}

	bool Logger::DeleteLogFile()
	{
		/// <summary>
		/// delete the log file
		/// </summary>
		bool result = loggerLogFile->Delete();
		m_logToFile = false;
		delete loggerLogFile;
		return result;
	}

	bool Logger::ClearLogFile()
	{
		/// <summary>
		/// clear the log file 
		/// </summary>
		return loggerLogFile->Clear();
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