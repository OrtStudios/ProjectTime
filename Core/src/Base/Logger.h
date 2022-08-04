#pragma once

#include <string>
#include <fstream>
#include <map>

namespace Core
{
	//public ref class Logger
	class Logger
	{
	private:
		std::string m_GetTheTimeNow(std::string UserFormat, bool TimeInTheDay = true);

		std::string m_PhraseFormat(std::string UserFormat, bool TimeInTheDay = true);

	public:
		enum LogType
		{
			DEBUG   = 0,
			INFO    = 1,
			WARNING = 2,
			_ERROR  = 3,
			FATAL   = 4,
			MASTER  = 5
		};

		//* Main Log Function
		void Log(const std::string message, LogType level);

		//* Log File
		void SetLogFile(const std::string directoryPath);

		std::string GetLogFilePath();

		bool CloseLogFile();

		bool SaveLogFile();

		bool DeleteLogFile();

		bool ClearLogFile();

		bool IsLogToFile();

		//* Log Level
		void SetLogLevel(LogType level);

		LogType GetLogLevel();

		//* Log To Console or Not
		void SetLogToConsole(bool logToConsole);

		//* Log To File or Not
		void SetLogToFile(bool logToFile);

	private:
		std::string m_dateFormat = "D.M";
		LogType m_logLevel = WARNING;
		bool m_logToConsole = true;
		bool m_logToFile = false;
		int debugColor = 90;

	};
}