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

CRaper void SetLogLevel(const char level)
{
	if (level == 'd')
	{
		Core::Logger::SetLogLevel(Core::Logger::DEBUG);
	}
	else if (level == 'i')
	{
		Core::Logger::SetLogLevel(Core::Logger::INFO);
	}
	else if (level == 'w')
	{
		Core::Logger::SetLogLevel(Core::Logger::WARNING);
	}
	else if (level == 'e')
	{
		Core::Logger::SetLogLevel(Core::Logger::_ERROR);
	}
	else if (level == 'f')
	{
		Core::Logger::SetLogLevel(Core::Logger::FATAL);
	}
	else
	{
		Core::Logger::SetLogLevel(Core::Logger::MASTER);
	}
}
//--------------------------------------------//
