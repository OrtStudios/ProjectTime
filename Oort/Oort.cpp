#include "pch.h"

#include "Oort.h"
#include <msclr\marshal_cppstd.h>
#include <string>

namespace OORT
{
	//* Main Oort Functions
	OortMain::OortMain()
	{
		logger = new Core::Logger();
	}

	OortMain::~OortMain()
	{
		delete logger;
	}

	//*//////////////////*//
	//*   Log Functions   *//
	//*//////////////////*//
	
	//* Main Log Function
	void OortMain::Log(System::String^ message, LogType level)
	{
		logger->Log(msclr::interop::marshal_as<std::string>(message), static_cast<Core::Logger::LogType>(level));
	}

	//* Log File
	void OortMain::SetLogFile(System::String^ directoryPath)
	{
		logger->SetLogFile(msclr::interop::marshal_as<std::string>(directoryPath));
	}

	System::String^ OortMain::GetLogFilePath()
	{
		return gcnew System::String(logger->GetLogFilePath().c_str());
	}

	bool OortMain::IsLogToFile()
	{
		return logger->IsLogToFile();
	}

	void OortMain::CloseLogFile()
	{
		logger->CloseLogFile();
	}

	void OortMain::SaveLogFile()
	{
		logger->SaveLogFile();
	}

	void OortMain::DeleteLogFile()
	{
		logger->DeleteLogFile();
	}
	
	void OortMain::ClearLogFile()
	{
		logger->ClearLogFile();
	}

	//* Log Level
	void OortMain::SetLogLevel(LogType level)
	{
		logger->SetLogLevel(static_cast<Core::Logger::LogType>(level));
	}

	LogType OortMain::GetLogLevel()
	{
		return static_cast<LogType>(logger->GetLogLevel());
	}

	//* Log To Console or Not
	void OortMain::SetLogToConsole(bool logToConsole)
	{
		logger->SetLogToConsole(logToConsole);
	}

	//* Log To File or Not
	void OortMain::SetLogToFile(bool logToFile)
	{
		logger->SetLogToFile(logToFile);
	}


	//*//////////////////*//
	//*   X Functions   *//
	//*//////////////////*//
}
