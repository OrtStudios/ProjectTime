// Core.cpp : Defines the functions for the static library.
#include "framework.h"
#include "Core.h"

using std::string;

#include "src/Base/Logger.h"

//--------------------------------------------//
//* Logger *//
CRaper void LogDebug(std::string message)
{
	Core::Logger().Log(message, Core::Logger::DEBUG);
}

CRaper void LogInfo(std::string message)
{
	Core::Logger().Log(message, Core::Logger::DEBUG);
}

CRaper void LogWarning(std::string message)
{
	Core::Logger().Log(message, Core::Logger::WARNING);
}

CRaper void LogError(std::string message)
{
	Core::Logger().Log(message, Core::Logger::_ERROR);
}

CRaper void LogFatal(std::string message)
{
	Core::Logger().Log(message, Core::Logger::FATAL);
}

CRaper void LogMaster(std::string message)
{
	Core::Logger().Log(message, Core::Logger::MASTER);
}
//--------------------------------------------//
