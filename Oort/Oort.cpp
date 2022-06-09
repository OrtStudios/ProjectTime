#include "pch.h"

#include "Oort.h"
#include <msclr\marshal_cppstd.h>
#include <string>

namespace Oort
{
	OortMain::OortMain()
	{
		logger = new Logger();
	}

	OortMain::~OortMain()
	{
		delete logger;
	}

	void OortMain::Log(System::String^ message, LogType level)
	{
		logger->Log(msclr::interop::marshal_as<std::string>(message), static_cast<Logger::LogType>(level));
	}

}
