// Core.cpp : Defines the functions for the static library.
#include "framework.h"
#include "Core.h"

using std::string;

#include "src/Base/Logger.h"

//--------------------------------------------//
//* Logger *//
CRaper void LogDebug(const std::string message)
{
	Core::Logger::Log(message, Core::Logger::DEBUG);
}

CRaper void LogInfo(const std::string message)
{
	Core::Logger::Log(message, Core::Logger::DEBUG);
}

CRaper void LogWarning(const std::string message)
{
	Core::Logger::Log(message, Core::Logger::WARNING);
}

CRaper void LogError(const std::string message)
{
	Core::Logger::Log(message, Core::Logger::_ERROR);
}

CRaper void LogFatal(const std::string message)
{
	Core::Logger::Log(message, Core::Logger::FATAL);
}

CRaper void LogMaster(const std::string message)
{
	Core::Logger::Log(message, Core::Logger::MASTER);
}

CRaper void SetLogLevel(LogType logLevel)
{
	if (logLevel == LogType::DEBUG)
	{
		Core::Logger::SetLogLevel(Core::Logger::DEBUG);
	}
	else if (logLevel == LogType::INFO)
	{
		Core::Logger::SetLogLevel(Core::Logger::INFO);
	}
	else if (logLevel == LogType::WARNING)
	{
		Core::Logger::SetLogLevel(Core::Logger::WARNING);
	}
	else if (logLevel == LogType::_ERROR)
	{
		Core::Logger::SetLogLevel(Core::Logger::_ERROR);
	}
	else if (logLevel == LogType::FATAL)
	{
		Core::Logger::SetLogLevel(Core::Logger::FATAL);
	}
	else
	{
		Core::Logger::SetLogLevel(Core::Logger::MASTER);
	}
}
//--------------------------------------------//
