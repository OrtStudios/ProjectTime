#include "pch.h"

#include "Basic_File.h"
#include "../Logger.h"

#include <iostream>
#include <string>
#include <fstream>
#include <format>
#include <filesystem>
#include <conio.h>

using std::string;

namespace Core
{
	// Private functions
	string* File::m_GetFullName(const string path)
	{
		/// <summary>
		/// get the full name, the extention and the name of the file
		/// </summary>
		/// <param name="path">the path to the file</param>
		/// <returns>the full name[0], the extention[1] and the file name(without the extention)[2]</returns>
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

	string File::m_GetModeName(const string mode)
	{
		/// <summary>
		/// get the mode name from the mode string
		/// </summary>
		/// <param name="mode"> the mode string </param>
		/// <returns> the mode name </returns>
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
	File::File(const string path, const string mode)
	{
		/// <summary>
		/// create the oort file
		/// </summary>
		/// <param name="path">the path to the file</param>
		/// <param name="mode">the mode of the file(r, w, a, r+, w+, a+)</param>
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

		// check if the file in the file path exists already
		if (std::filesystem::exists(path))
		{
			m_isExists = true; // the file exists
			logger.Log("file exists in the path specified", Logger::LogType::DEBUG);
		}
		else
		{
			m_isExists = false; // the file doesn't exists
			logger.Log("file don't exists in the path specified", Logger::LogType::DEBUG);
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
	
	File::~File()
	{
		/// <summary>
		/// delete the oort file object (don't delete the file itself)
		/// </summary>
		Logger logger = Logger();
		delete &m_file;
		logger.Log("basic file destroyed", Logger::LogType::INFO);

		// delete logger
		delete &logger;
	}

	// Main Functions
	bool File::Open()
	{
		/// <summary>
		/// open the oort file in the mode you have chosen in the constructor
		/// </summary>
		/// <returns>TRUE if succeeded, FALSE if didn't</returns>
		
		if (m_isOpen)
		{
			Logger logger = Logger();
			logger.Log("Warning:\n    the file is already open", Logger::LogType::WARNING);
			delete& logger;
			return true;
		}
		
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

	bool File::Close()
	{
		/// <summary>
		/// close the file
		/// </summary>
		/// <returns>TRUE if succeeded, FALSE if didn't</returns>
		
		if (!m_isOpen)
		{
			Logger logger = Logger();
			logger.Log("Warning:\n    the file is already closed", Logger::LogType::WARNING);
			delete& logger;
			return true;
		}
		
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

	bool File::Save()
	{
		/// <summary>
		/// save the file
		/// </summary>
		/// <returns>TRUE if succeeded, FALSE if didn't</returns>
		Logger logger = Logger();
		logger.Log("Saving file", Logger::LogType::INFO);
		
		Close();
		Open();
		
		logger.Log("File saved", Logger::LogType::INFO);

		delete& logger;
		return true;
	}

	// Read & Write Functions
	string File::Read()
	{
		/// <summary>
		/// read the file and return the content
		/// </summary>
		/// <returns>the content of the file</returns>
		Logger logger = Logger();
		bool alreadyOpened = false;

		// open the file if it wasn't already open and then read it, then  return the whole file to the user as string
		if (!m_isOpen)
		{
			logger.Log("file is not open, opening it", Logger::LogType::DEBUG);
			if (!Open())
			{
				logger.Log("file can't be opened(Error massage in the open function), returning empty string", Logger::LogType::DEBUG);
				return "";
			}
		}
		else
		{
			logger.Log("file is already open, reading it", Logger::LogType::DEBUG);
			alreadyOpened = true;
		}
		
		string result;
		std::getline(m_file, result);
		
		if (!alreadyOpened)
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
	
	bool File::Write(const string str)
	{
		/// <summary>
		/// write the string to the file
		/// </summary>
		/// <param name="str">the string to write</param>
		/// <returns>TRUE if succeeded, FALSE if didn't</returns>
		Logger logger = Logger();
		bool alreadyOpened = false;
		
		// open the file if it wasn't already open and then write the string to the file, then close the file
		if (!m_isOpen)
		{
			logger.Log("file is not open, opening it", Logger::LogType::DEBUG);
			if (!Open())
			{
				logger.Log("file can't be opened(Error massage in the open function), returning false", Logger::LogType::DEBUG);
				return false;
			}
		}
		else
		{
			logger.Log("file is already open, writing to it", Logger::LogType::DEBUG);
			alreadyOpened = true;
		}
		
		m_file << str;
		
		if (!alreadyOpened)
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

	bool File::Clear()
	{
		/// <summary>
		/// clear the file
		/// </summary>
		/// <returns>TRUE if succeeded, FALSE if didn't</returns>
		Logger logger = Logger();
		bool alreadyOpened = false;
		
		// open the file if it wasn't already open and then clear the file, then close the file
		if (!m_isOpen)
		{
			logger.Log("file is not open, opening it", Logger::LogType::DEBUG);
			if (!Open())
			{
				logger.Log("file can't be opened(Error massage in the open function), returning false", Logger::LogType::DEBUG);
				return false;
			}
		}
		else
		{
			logger.Log("file is already open, clearing it", Logger::LogType::DEBUG);
			alreadyOpened = true;
		}
		
		m_file.clear();
		
		if (!alreadyOpened)
		{
			logger.Log("closing the file", Logger::LogType::DEBUG);
			Close();
		}
		
		logger.Log(std::format("file: '{}' cleared", m_path), Logger::LogType::INFO);
		
		// delete logger
		delete &logger;
		
		// return true if the file was cleared
		return true;
	}

	// Cartography Functions
	bool File::Encrypt(const int key)
	{
		/// <summary>
		/// encrypt the file with a custom key
		/// </summary>
		/// <param name="key">the key that the file will be encrypted with</param>
		/// <returns>TRUE if succeeded or FALSE if failed</returns>

		Logger logger = Logger();

		// close the file if it was open, open the file in binary mode
		if (m_isOpen)
		{
			logger.Log("file is open, closing it", Logger::LogType::DEBUG);
			Close();
		}
		
		logger.Log("opening the file in binary mode", Logger::LogType::DEBUG);

		//* Opening Files *//
		// main file
		try
		{
			m_file.open(m_path, std::ios::binary);
			m_isOpen = true;
		}
		catch (std::exception& e)
		{
			logger.Log(std::format("Error:\n    the file: '{}' can't be opened", m_path), Logger::LogType::ERROR);
			m_isOpen = false;

			// delete logger
			delete& logger;

			return false;
		}
		
		// output file
		std::ofstream fout;
		try
		{
			fout.open("output.txt", std::ios::binary);
		}
		catch (std::exception& e)
		{
			logger.Log(std::format("Error:\n    the file: '{}' can't be opened", "output.txt"), Logger::LogType::ERROR);
			m_isOpen = false;

			// delete logger
			delete& logger;

			return false;
		}
		
		//* Encrypting the file *//
		char c;
		logger.Log("Encrypting the file", Logger::LogType::INFO);
		while (!m_file.eof())
		{
			m_file >> std::noskipws >> c;
			logger.Log(std::format("Encrypting char: {}", c), Logger::LogType::DEBUG);
			int temp = c + key;
			fout << (char)temp;
		}
		logger.Log("Output file encrypted", Logger::LogType::DEBUG);

		
		//* Closing Files *//
		// output file
		try
		{
			fout.close();
		}
		catch (std::exception& e)
		{
			logger.Log(
				std::format("Error:\n    the file: '{}' can't be closed", "output.txt"),
				Logger::LogType::ERROR);
			m_isOpen = true;

			// delete logger
			delete& logger;

			return false;
		}

		// setting the content of the output file to the main file and deleting the output file
		logger.Log("setting the content of the output file to the main file", Logger::LogType::DEBUG);
		std::ifstream fin;
		try
		{
			fin.open("output.txt", std::ios::binary);
		}
		catch (std::exception& e)
		{
			logger.Log(
				std::format("Error:\n    the file: '{}' can't be opened", "output.txt"),
				Logger::LogType::ERROR);
			m_isOpen = false;

			// delete logger
			delete& logger;

			return false;
		}

		//* Closing Files *//
		// setting the content of the output file to the main file
		char c2;
		logger.Log("setting the content of the output file to the main file", Logger::LogType::DEBUG);
		while (!fin.eof())
		{
			fin >> std::noskipws >> c2;
			m_file << (char) c2;
		}
		logger.Log("File encrypted", Logger::LogType::INFO);

		// closing the output file
		try
		{
			fin.close();
		}
		catch (std::exception& e)
		{
			logger.Log(
				std::format("Error:\n    the file: '{}' can't be closed", m_path),
				Logger::LogType::ERROR);
			m_isOpen = true;

			// delete logger
			delete& logger;

			return false;
		}

		// deleting the output file
		try
		{
			remove("output.txt");
		}
		catch (std::exception& e)
		{
			logger.Log(
				std::format("Error:\n    the file: '{}' can't be deleted", "output.txt"),
				Logger::LogType::ERROR);
			m_isOpen = true;

			// delete logger
			delete& logger;

			return false;
		}
		
		// closing the main file
		try
		{
			m_file.close();
			m_isOpen = false;
		}
		catch (std::exception& e)
		{
			logger.Log(
				std::format("Error:\n    the file: '{}' can't be closed", m_path),
				Logger::LogType::ERROR);
			m_isOpen = true;

			// delete logger
			delete& logger;

			return false;
		}
		

		//* Deleting the logger and returning true *//
		delete &logger;
		return true;
	}
	
	bool File::Decrypt(const int key)
	{
		/// <summary>
		/// decrypt the file with a custom key
		/// </summary>
		/// <param name="key">the key that the file will be decrypted with</param>
		/// <returns>TRUE if succeeded or FALSE if failed</returns>

		Logger logger = Logger();

		// close the file if it was open, open the file in binary mode
		if (m_isOpen)
		{
			logger.Log("file is open, closing it", Logger::LogType::DEBUG);
			Close();
		}

		logger.Log("opening the file in binary mode", Logger::LogType::DEBUG);

		//* Opening Files *//
		// main file
		try
		{
			m_file.open(m_path, std::ios::binary);
			m_isOpen = true;
		}
		catch (std::exception& e)
		{
			logger.Log(std::format("Error:\n    the file: '{}' can't be opened", m_path), Logger::LogType::ERROR);
			m_isOpen = false;

			// delete logger
			delete& logger;

			return false;
		}

		// output file
		std::ofstream fout;
		try
		{
			fout.open(m_path.c_str(), std::ios::binary);
		}
		catch (std::exception& e)
		{
			logger.Log(std::format("Error:\n    the file: '{}' can't be opened", m_path), Logger::LogType::ERROR);
			m_isOpen = false;

			// delete logger
			delete& logger;

			return false;
		}

		//* Decrypting the file *//
		logger.Log("Decrypting the file", Logger::LogType::INFO);
		char c;
		while (!m_file.eof())
		{
			m_file >> std::noskipws >> c;
			logger.Log(std::format("Decrypting char: {}", c), Logger::LogType::DEBUG);
			int temp = c - key;
			fout << (char)temp;
		}
		logger.Log("File decrypted", Logger::LogType::INFO);


		//* Closing Files *//
		// main file
		try
		{
			m_file.close();
			m_isOpen = false;
		}
		catch (std::exception& e)
		{
			logger.Log(
				std::format("Error:\n    the file: '{}' can't be closed", m_path),
				Logger::LogType::ERROR);
			m_isOpen = true;

			// delete logger
			delete& logger;

			return false;
		}

		// output file
		try
		{
			fout.close();
		}
		catch (std::exception& e)
		{
			logger.Log(
				std::format("Error:\n    the file: '{}' can't be closed", m_path),
				Logger::LogType::ERROR);
			m_isOpen = true;

			// delete logger
			delete& logger;

			return false;
		}

		//* Deleting the logger and returning true *//
		delete& logger;
		return true;
	}

	// Check Parameters
	bool File::IsOpen()
	{
		return m_isOpen;
	}

	bool File::IsExists()
	{
		return m_isExists;
	}

	bool File::IsReadable()
	{
		return m_isReadable;
	}

	bool File::IsWritable()
	{
		return m_isWritable;
	}

	// Get Parameters
	string File::GetPath()
	{
		return m_path;
	}

	string File::GetName()
	{
		return m_name;
	}

	string File::GetExtension()
	{
		return m_extension;
	}

	string File::GetFullName()
	{
		return m_fullName;
	}

	// Delete File
	bool File::Delete()
	{
		/// <summary>
		/// delete the file itself (not the OortFile object)
		/// </summary>
		/// <returns></returns>
		
		Logger logger = Logger();
		logger.Log("Deleting the file", Logger::LogType::INFO);
		try
		{
			remove(m_path.c_str());
		}
		catch (std::exception& e)
		{
			logger.Log(std::format("Error:\n    the file: '{}' can't be deleted", m_path), Logger::LogType::ERROR);
			return false;
		}
		logger.Log("File deleted", Logger::LogType::INFO);
		delete& logger;
		return true;
	}
}
