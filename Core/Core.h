#pragma once

#include <string>

#define CRaper _declspec(dllexport)

extern "C"
{
	//* Logger *//
	enum LogType
	{
		DEBUG = 0,
		INFO = 1,
		WARNING = 2,
		ERROR = 3,
		FATAL = 4,
		MASTER = 5
	};

	CRaper void LogDebug   (std::string message );
	CRaper void LogInfo    (std::string message );
	CRaper void LogWarning (std::string message );
	CRaper void LogError   (std::string message );
	CRaper void LogFatal   (std::string message );
	CRaper void LogMaster  (std::string message );
	CRaper void SetLogLevel(LogType     logLevel);
}