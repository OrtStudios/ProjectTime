// Core.cpp : Defines the functions for the static library.
#include "framework.h"
#include "Core.h"

using std::string;

#include "./src/Base/Logger.h"

CRaper void LogTest(string message)
{
	Core::Logger logger = Core::Logger();
	
	logger.Log(message, Core::Logger::MASTER);
}
