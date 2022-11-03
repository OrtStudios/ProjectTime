// Core.cpp : Defines the functions for the static library.
#include "framework.h"
#include "Core.h"

using std::string;

#include "src/Base/Logger.h"

//--------------------------------------------//
//* Logger *//
CRaper void LogDebug(const std::string message)
{
	Core::Logger::Log(message, Core::Logger::LogType::DEBUG);
}

CRaper void LogInfo(const std::string message)
{
	Core::Logger::Log(message, Core::Logger::LogType::DEBUG);
}

CRaper void LogWarning(const std::string message)
{
	Core::Logger::Log(message, Core::Logger::LogType::WARNING);
}

CRaper void LogError(const std::string message)
{
	Core::Logger::Log(message, Core::Logger::LogType::ERROR);
}

CRaper void LogFatal(const std::string message)
{
	Core::Logger::Log(message, Core::Logger::LogType::FATAL);
}

CRaper void LogMaster(const std::string message)
{
	Core::Logger::Log(message, Core::Logger::LogType::MASTER);
}

CRaper void SetLogLevel(Core::Logger::LogType logLevel)
{
	Core::Logger::SetLogLevel(logLevel);
}
//--------------------------------------------//
