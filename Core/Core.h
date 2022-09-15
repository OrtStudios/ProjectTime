#pragma once

#include <string>

#define CRaper _declspec(dllexport)

extern "C"
{
	//* Logger *//
	CRaper void LogDebug   (std::string message);
	CRaper void LogInfo    (std::string message);
	CRaper void LogWarning (std::string message);
	CRaper void LogError   (std::string message);
	CRaper void LogFatal   (std::string message);
	CRaper void LogMaster  (std::string message);
	CRaper void SetLogLevel(const char  level  );
}