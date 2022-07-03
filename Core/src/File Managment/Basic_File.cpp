#include "pch.h"

#include "Basic_File.h"
#include "../Logger.h"

#include <iostream>
#include <string>
#include <fstream>
#include <format>
#include <filesystem>

using std::string;

namespace Core
{
	// Private functions
	string* OortFile::m_GetFullName(const string path)
	{
		string* result = new string[3];

		// find the full name
		size_t lastSlash = path.find_last_of("/");

		if (lastSlash == std::string::npos)
		{
			lastSlash = path.find_last_of("\\");
		}
		
		if (lastSlash == std::string::npos) 
		{
			throw std::invalid_argument(std::format("Error:\n    the file path: '{}' is invalid", path));
		}

		result[0] = path.substr(lastSlash);
		
		// find the extention
		size_t lastDot = path.find_last_of(".");

		if (lastDot == std::string::npos)
		{
			throw std::invalid_argument(std::format("Error:\n    the file path: '{}' is invalid", path));
		}

		result[1] = path.substr(lastDot);

		// find the name
		result[2] = path.substr(lastSlash, lastDot - lastSlash);

		return result;
	}

	string OortFile::m_GetModeName(const string mode)
	{
		if (mode == "r")
		{
			return "read";
		}
		else if (mode == "w")
		{
			return "write";
		}
		else if (mode == "a")
		{
			return "append";
		}
		else if (mode == "r+")
		{
			return "read and write";
		}
		else if (mode == "w+")
		{
			return "write and read";
		}
		else if (mode == "a+")
		{
			return "append and read";
		}
		else
		{
			throw std::invalid_argument(std::format("Error:\n    the file mode: '{}' is invalid", mode));
		}
	}

	// Constructor & Destructor
	OortFile::OortFile(const string path, const string mode)
	{
		Logger logger = Logger();
		logger.Log("Creating basic file", Logger::LogType::INFO);

		// set the mode
		// modes:
		//    "r" - read
		//    "w" - write
		//    "a" - append [TODO]
		//    "r+" - read and write [TODO]
		//    "w+" - write and read [TODO]
		//    "a+" - append and read [TODO]
		m_mode = mode;
		logger.Log(std::format("file mode is: {} mode", m_GetModeName(mode)), Logger::LogType::DEBUG);

		// open the file
		m_file = std::fstream(path);
		logger.Log(std::format("file path is: {}", path), Logger::LogType::INFO);

		// get the full name
		string* result = m_GetFullName(path);
		
		// the full name is the name of the file with the extention
		// the name is the name of the file without the extention ( like "test.txt" -> "test" )
		// the extention is the extention of the file( like .txt, .png, .jpg, .docx, .exe, etc.)
		m_fullName = result[0];
		m_extension = result[1];
		m_name = result[2];

		// check if the file in the file path exsist alredy
		if (std::filesystem::exists(path))
		{
			m_isExists = true; // the file exsist
			logger.Log("file exsist in the path spacified", Logger::LogType::DEBUG);
		}
		else
		{
			m_isExists = false; // the file doesn't exsist
			logger.Log("file don't exsist in the path spacified", Logger::LogType::DEBUG);
		}
		
		// check if the file is open
		// if the file is open, close it to not use the file when not needed to be able to open it from other programs
		// if not open, just set the var
		if (m_file.is_open())
		{
			m_file.close();
			m_isOpen = false;
		}
		else
			m_isOpen = false;
		
		logger.Log("basic file created", Logger::LogType::INFO);

		//* delete the temp staff *\\
		// delete the string array
		delete[] result;
		// delete the logger
		delete &logger;
	}
	
	OortFile::~OortFile()
	{
		Logger logger = Logger();
		delete &m_file;
		logger.Log("basic file destroyed", Logger::LogType::INFO);

		// delete logger
		delete &logger;
	}

	// Main Functions
	bool OortFile::Open()
	{
		try
		{
			m_file.open(m_path);
			m_isOpen = true;
			return true;
		}
		catch (std::exception& e)
		{
			Logger logger = Logger();
			logger.Log(std::format("Error:\n    the file: '{}' can't be opened", m_path), Logger::LogType::ERROR);
			m_isOpen = false;

			// delete logger
			delete &logger;

			return false;
		}
	}

	bool OortFile::Close()
	{
		try
		{
			m_file.close();
			m_isOpen = false;
			return true;
		}
		catch (std::exception& e)
		{
			Logger logger = Logger();
			logger.Log(
				std::format("Error:\n    the file: '{}' can't be closed", m_path),
				Logger::LogType::ERROR);
			m_isOpen = true;

			// delete logger
			delete &logger;

			return false;
		}
	}

	// Read & Write Functions
	string OortFile::Read()
	{
		Logger logger = Logger();
		bool alredyOpend = false;

		// open the file if it wansnt alredy open and then read it, then  return the whol file to the user as string
		if (!m_isOpen)
		{
			logger.Log("file is not open, opening it", Logger::LogType::DEBUG);
			if (!Open())
			{
				logger.Log("file can't be opened(Error massege in the open function), returning empty string", Logger::LogType::DEBUG);
				return "";
			}
		}
		else
		{
			logger.Log("file is already open, reading it", Logger::LogType::DEBUG);
			alredyOpend = true;
		}
		
		string result;
		std::getline(m_file, result);
		
		if (!alredyOpend)
		{
			logger.Log("closing the file", Logger::LogType::DEBUG);
			Close();
		}

		logger.Log(std::format("file: '{}' read", m_path), Logger::LogType::DEBUG);
		logger.Log(std::format("The file<{}> content: {}", m_path, result), Logger::LogType::INFO);
		
		// delete logger
		delete &logger;

		// return the file content
		return result;
	}
	
	bool OortFile::Write(const string str)
	{
		Logger logger = Logger();
		bool alredyOpend = false;
		
		// open the file if it wansnt alredy open and then write the string to the file, then close the file
		if (!m_isOpen)
		{
			logger.Log("file is not open, opening it", Logger::LogType::DEBUG);
			if (!Open())
			{
				logger.Log("file can't be opened(Error massege in the open function), returning false", Logger::LogType::DEBUG);
				return false;
			}
		}
		else
		{
			logger.Log("file is already open, writing to it", Logger::LogType::DEBUG);
			alredyOpend = true;
		}
		
		m_file << str;
		
		if (!alredyOpend)
		{
			logger.Log("closing the file", Logger::LogType::DEBUG);
			Close();
		}
		
		logger.Log(std::format("file: '{}' written", m_path), Logger::LogType::DEBUG);
		logger.Log(std::format("The file<{}> content: {}", m_path, str), Logger::LogType::INFO);
		
		// delete logger
		delete &logger;
		
		// return true if the file was written
		return true;
	}

	// Cartography Functions
	bool OortFile::Encrypt(const int key)
	{
		return false;
	}
	
	bool OortFile::Decrypt(const int key)
	{
		return false;
	}

	// Check Parameters
	bool OortFile::IsOpen()
	{
		return m_isOpen;
	}

	bool OortFile::IsExists()
	{
		return m_isExists;
	}

	bool OortFile::IsReadable()
	{
		return m_isReadable;
	}

	bool OortFile::IsWritable()
	{
		return m_isWritable;
	}

	// Get Parameters
	string OortFile::GetPath()
	{
		return m_path;
	}

	string OortFile::GetName()
	{
		return m_name;
	}

	string OortFile::GetExtension()
	{
		return m_extension;
	}

	string OortFile::GetFullName()
	{
		return m_fullName;
	}
}
