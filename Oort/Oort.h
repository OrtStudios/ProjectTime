#pragma once

#include "../Core/src/Logger.h"

namespace OORT
{
	public enum class LogType
	{
		LOG_TYPE_DEBUG = 0,
		LOG_TYPE_INFO = 1,
		LOG_TYPE_WARNING = 2,
		LOG_TYPE_ERROR = 3,
		LOG_TYPE_FATAL = 4,
		LOG_TYPE_MASTER = 5
	};
	
	public ref class OortMain
	{
	public:	
		OortMain();
		~OortMain();

		
		//*//////////////////*//
		//*   Log Functions   *//
		//*//////////////////*//
		//* Main Log Function
		void Log(System::String^ message, LogType level);

		//* Log File
		void SetLogFile(System::String^ directoryPath);

		System::String^ GetLogFilePath();

		void CloseLogFile();

		void SaveLogFile();

		//* Log Level
		void SetLogLevel(LogType level);

		LogType GetLogLevel();

		//* Log To Console or Not
		void SetLogToConsole(bool logToConsole);

		//* Log To File or Not
		void SetLogToFile(bool logToFile);

		
		//*//////////////////*//
		//*   X Functions   *//
		//*//////////////////*//
		
	private:
		Core::Logger *logger;
	};
}
