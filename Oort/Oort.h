#pragma once

#include "Core/src/Logger.h"

namespace OORT
{
	public enum class LogType
	{
		DEBUG = 0,
		INFO = 1,
		WARNING = 2,
		ERROR = 3,
		FATAL = 4,
		MASTER = 5
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

		bool IsLogToFile();

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
