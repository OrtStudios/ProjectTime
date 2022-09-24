#pragma once

#include <string>
#include <fstream>
#include <map>

#ifdef ERROR
#undef ERROR
#endif

namespace Core
{
	//public ref class Logger
	class Logger
	{
	public:
		enum class LogType
		{
			DEBUG   = 0,
			INFO    = 1,
			WARNING = 2,
			ERROR   = 3,
			FATAL   = 4,
			MASTER  = 5
		};

		//* Main Log Function
		static void Log(const std::string message, LogType level);

		//* Log File
		static void SetLogFile(const std::string directoryPath);

		static std::string GetLogFilePath();

		static bool CloseLogFile();

		static bool SaveLogFile();

		static bool DeleteLogFile();

		static bool ClearLogFile();

		static bool IsLogToFile();

		//* Log Level
		static void SetLogLevel(Logger::LogType level);

		static LogType GetLogLevel();

		//* Log To Console or Not
		static void SetLogToConsole(bool logToConsole);

		//* Log To File or Not
		static void SetLogToFile(bool logToFile);

	private:
		static std::string m_dateFormat;
		static LogType m_logLevel;
		static bool m_logToConsole;
		static bool m_logToFile;
		static int debugColor;
	};
}