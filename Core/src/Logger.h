#pragma once

#include <string>
#include <fstream>
#include <map>

namespace Oort
{
	//public ref class Logger
	class Logger
	{
	private:
		int nthOccurrence(const std::string str, const std::string findMe, int nth);

	public:
		enum LogType
		{
			LOG_TYPE_DEBUG = 0,
			LOG_TYPE_INFO = 1,
			LOG_TYPE_WARNING = 2,
			LOG_TYPE_ERROR = 3,
			LOG_TYPE_FATAL = 4,
			LOG_TYPE_MASTER = 5
		};

		//* Main Log Function
		void Log(const std::string message, LogType level);

		//* Log File
		void SetLogFile(const std::string directoryPath);

		std::string GetLogFilePath();

		void CloseLogFile();

		void SaveLogFile();

		//* Log Level
		void SetLogLevel(LogType level);

		LogType GetLogLevel();

		//* Log To Console or Not
		void SetLogToConsole(bool logToConsole);

		// Log To File or Not
		void SetLogToFile(bool logToFile);

	private:
		std::string m_logDirectoryPath = "";
		std::string m_logFileName = "";
		std::string m_FullPath = "";
		std::string m_dateFormat = "D.M";
		LogType m_logLevel = LOG_TYPE_WARNING;
		bool m_logToConsole = true;
		bool m_logToFile = false;
		int debugColor = 90;
		std::ofstream m_logFile;
	};
}