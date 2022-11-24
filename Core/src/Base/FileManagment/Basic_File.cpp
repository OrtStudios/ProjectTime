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
			lastSlash = path.find_last_of("\\");
		
		if (lastSlash == std::string::npos) 
			throw std::invalid_argument(std::format("Error:\n    the file path: '{}' is invalid", path));

		result[0] = path.substr(lastSlash);
		
		// find the extention
		size_t lastDot = path.find_last_of(".");

		if (lastDot == std::string::npos)
			throw std::invalid_argument(std::format("Error:\n    the file path: '{}' is invalid", path));

		result[1] = path.substr(lastDot);

		// find the name
		result[2] = path.substr(lastSlash, lastDot - lastSlash);

		return result;
	}

	// Constructor & Destructor
	File::File(const string path)
	{
		/// <summary>
		/// create the oort file
		/// </summary>
		/// <param name="path">the path to the file</param>
		Logger::Log("Creating basic file", Logger::LogType::INFO);

		// open the file
		m_file = std::fstream(path);
		Logger::Log(std::format("file path is: {}", path), Logger::LogType::INFO);

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
			Logger::Log("file exists in the path specified", Logger::LogType::DEBUG);
		}
		else
		{
			m_isExists = false; // the file doesn't exists
			Logger::Log("file don't exists in the path specified", Logger::LogType::DEBUG);
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
		
		Logger::Log("basic file created", Logger::LogType::INFO);
	}
	
	File::~File()
	{
		/// <summary>
		/// delete the oort file object (don't delete the file itself)
		/// </summary>		
		Close();

		delete& m_file;
		Logger::Log("basic file deleted", Logger::LogType::INFO);
		
	}

	// Main Functions
	bool File::Open()
	{
		/// <summary>
		/// open the file
		/// </summary>
		/// <returns>TRUE if succeeded, FALSE if didn't</returns>
		
		if (m_isOpen)
		{
			Logger::Log("Warning:\n    the file is already open", Logger::LogType::WARNING);
			return true;
		}
		
		try
		{
			m_file.open(m_path);
			m_isOpen = true;
			return true;
		}
		catch (std::exception&)
		{
			
			Logger::Log(std::format("Error:\n    the file: '{}' can't be opened", m_path), Logger::LogType::ERROR);
			m_isOpen = false;

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
			
			Logger::Log("Warning:\n    the file is already closed", Logger::LogType::WARNING);
			
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
			
			Logger::Log(
				std::format("Error:\n    the file: '{}' can't be closed", m_path),
				Logger::LogType::ERROR);
			m_isOpen = true;

			return false;
		}
	}

	bool File::Save()
	{
		/// <summary>
		/// save the file
		/// </summary>
		/// <returns>TRUE if succeeded, FALSE if didn't</returns>
		
		Logger::Log("Saving file", Logger::LogType::INFO);
		
		Close();
		Open();
		
		Logger::Log("File saved", Logger::LogType::INFO);

		
		return true;
	}

	// Read & Write Functions
	string File::Read()
	{
		/// <summary>
		/// read the file and return the content
		/// </summary>
		/// <returns>the content of the file</returns>
		
		bool alreadyOpened = false;

		// open the file if it wasn't already open and then read it, then  return the whole file to the user as string
		if (!m_isOpen)
		{
			Logger::Log("file is not open, opening it", Logger::LogType::DEBUG);
			if (!Open())
			{
				Logger::Log("file can't be opened(Error massage in the open function), returning empty string", Logger::LogType::DEBUG);
				return "";
			}
		}
		else
		{
			Logger::Log("file is already open, reading it", Logger::LogType::DEBUG);
			alreadyOpened = true;
		}
		
		string result;
		std::getline(m_file, result);
		
		if (!alreadyOpened)
		{
			Logger::Log("closing the file", Logger::LogType::DEBUG);
			Close();
		}

		Logger::Log(std::format("file: '{}' read", m_path), Logger::LogType::DEBUG);
		Logger::Log(std::format("The file<{}> content: {}", m_path, result), Logger::LogType::INFO);
		
		
		

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
		
		bool alreadyOpened = false;
		
		// open the file if it wasn't already open and then write the string to the file, then close the file
		if (!m_isOpen)
		{
			Logger::Log("file is not open, opening it", Logger::LogType::DEBUG);
			if (!Open())
			{
				Logger::Log("file can't be opened(Error massage in the open function), returning false", Logger::LogType::DEBUG);
				return false;
			}
		}
		else
		{
			Logger::Log("file is already open, writing to it", Logger::LogType::DEBUG);
			alreadyOpened = true;
		}
		
		m_file << str;
		
		if (!alreadyOpened)
		{
			Logger::Log("closing the file", Logger::LogType::DEBUG);
			Close();
		}
		
		Logger::Log(std::format("file: '{}' written", m_path), Logger::LogType::DEBUG);
		Logger::Log(std::format("The file<{}> content: {}", m_path, str), Logger::LogType::INFO);
		
		// return true if the file was written
		return true;
	}

	bool File::Clear()
	{
		/// <summary>
		/// clear the file
		/// </summary>
		/// <returns>TRUE if succeeded, FALSE if didn't</returns>
		
		bool alreadyOpened = false;
		
		// open the file if it wasn't already open and then clear the file, then close the file
		if (!m_isOpen)
		{
			Logger::Log("file is not open, opening it", Logger::LogType::DEBUG);
			if (!Open())
			{
				Logger::Log("file can't be opened(Error massage in the open function), returning false", Logger::LogType::DEBUG);
				return false;
			}
		}
		else
		{
			Logger::Log("file is already open, clearing it", Logger::LogType::DEBUG);
			alreadyOpened = true;
		}
		
		m_file.clear();
		
		if (!alreadyOpened)
		{
			Logger::Log("closing the file", Logger::LogType::DEBUG);
			Close();
		}
		
		Logger::Log(std::format("file: '{}' cleared", m_path), Logger::LogType::INFO);
		
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
		bool wasOpen = false;

		// close the file if it was open, open the file in binary mode
		if (m_isOpen)
		{
			Logger::Log("file is open, closing it", Logger::LogType::DEBUG);
			wasOpen = true;
			Close();
		}
		
		Logger::Log("opening the file in binary mode", Logger::LogType::DEBUG);

		//* Opening Files *//
		// main file
		try
		{
			m_file.open(m_path, std::ios::binary);
			m_isOpen = true;
		}
		catch (std::exception& e)
		{
			Logger::Log(std::format("Error:\n    the file: '{}' can't be opened", m_path), Logger::LogType::ERROR);
			m_isOpen = false;

			return false;
		}
		
		// output file
		std::ofstream fout;
		try
		{
			fout.open("temp.txt", std::ios::binary);
		}
		catch (std::exception& e)
		{
			Logger::Log(std::format("Error:\n    the file: '{}' can't be opened", "temp.txt"), Logger::LogType::ERROR);
			m_isOpen = false;

			return false;
		}
		
		//* Encrypting the file *//
		char c;
		Logger::Log("Encrypting the file", Logger::LogType::INFO);
		while (!m_file.eof())
		{
			m_file >> std::noskipws >> c;
			Logger::Log(std::format("Encrypting char: {}", c), Logger::LogType::DEBUG);
			int temp = c + key;
			fout << (char)temp;
		}
		Logger::Log("Output file encrypted", Logger::LogType::DEBUG);

		
		//* Closing Files *//
		// output file
		try
		{
			fout.close();
		}
		catch (std::exception& e)
		{
			Logger::Log(
				std::format("Error:\n    the file: '{}' can't be closed", "temp.txt"),
				Logger::LogType::ERROR);
			m_isOpen = true;

			return false;
		}

		// setting the content of the output file to the main file and deleting the output file
		Logger::Log("setting the content of the output file to the main file", Logger::LogType::DEBUG);
		std::ifstream fin;
		try
		{
			fin.open("temp.txt", std::ios::binary);
		}
		catch (std::exception& e)
		{
			Logger::Log(
				std::format("Error:\n    the file: '{}' can't be opened", "temp.txt"),
				Logger::LogType::ERROR);
			m_isOpen = false;

			return false;
		}

		//* Closing Files *//
		// setting the content of the output file to the main file
		char c2;
		Logger::Log("setting the content of the output file to the main file", Logger::LogType::DEBUG);
		while (!fin.eof())
		{
			fin >> std::noskipws >> c2;
			m_file << (char) c2;
		}
		Logger::Log("File encrypted", Logger::LogType::INFO);

		// closing the output file
		try
		{
			fin.close();
		}
		catch (std::exception& e)
		{
			Logger::Log(
				std::format("Error:\n    the file: '{}' can't be closed", m_path),
				Logger::LogType::ERROR);
			m_isOpen = true;

			return false;
		}

		// deleting the output file
		try
		{
			remove("temp.txt");
		}
		catch (std::exception& e)
		{
			Logger::Log(
				std::format("Error:\n    the file: '{}' can't be deleted", "temp.txt"),
				Logger::LogType::ERROR);
			m_isOpen = true;

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
			Logger::Log(
				std::format("Error:\n    the file: '{}' can't be closed", m_path),
				Logger::LogType::ERROR);
			m_isOpen = true;

			return false;
		}
		
		if (wasOpen)	
		{
			Logger::Log("file was open, opening it again", Logger::LogType::DEBUG);
			Open();
		}
		
		return true;
	}
	
	bool File::Decrypt(const int key)
	{
		/// <summary>
		/// decrypt the file with a custom key
		/// </summary>
		/// <param name="key">the key that the file will be decrypted with</param>
		/// <returns>TRUE if succeeded or FALSE if failed</returns>
		
		bool wasOpen = false;

		// close the file if it was open, open the file in binary mode
		if (m_isOpen)
		{
			Logger::Log("file is open, closing it", Logger::LogType::DEBUG);
			wasOpen = true;
			Close();
		}

		Logger::Log("opening the file in binary mode", Logger::LogType::DEBUG);

		//* Opening Files *//
		// main file
		try
		{
			m_file.open(m_path, std::ios::binary);
			m_isOpen = true;
		}
		catch (std::exception& e)
		{
			Logger::Log(std::format("Error:\n    the file: '{}' can't be opened", m_path), Logger::LogType::ERROR);
			m_isOpen = false;

			return false;
		}

		// output file
		std::ofstream fout;
		try
		{
			fout.open("temp.txt", std::ios::binary);
		}
		catch (std::exception& e)
		{
			Logger::Log(std::format("Error:\n    the file: '{}' can't be opened", "temp.txt"), Logger::LogType::ERROR);
			m_isOpen = false;

			return false;
		}

		//* Decrypting the file *//
		char c;
		Logger::Log("Decrypting the file", Logger::LogType::INFO);
		while (!m_file.eof())
		{
			m_file >> std::noskipws >> c;
			Logger::Log(std::format("Decrypting char: {}", c), Logger::LogType::DEBUG);
			int temp = c - key;
			fout << (char)temp;
		}
		Logger::Log("Output file decrypted", Logger::LogType::DEBUG);


		//* Closing Files *//
		// output file
		try
		{
			fout.close();
		}
		catch (std::exception& e)
		{
			Logger::Log(
				std::format("Error:\n    the file: '{}' can't be closed", "temp.txt"),
				Logger::LogType::ERROR);
			m_isOpen = true;

			return false;
		}

		//* setting the content of the output file to the main file and deleting the output file
		Logger::Log("setting the content of the output file to the main file", Logger::LogType::DEBUG);
		std::ifstream fin;
		try
		{
			fin.open("temp.txt", std::ios::binary);
		}
		catch (std::exception& e)
		{
			Logger::Log(
				std::format("Error:\n    the file: '{}' can't be opened", "temp.txt"),
				Logger::LogType::ERROR);
			m_isOpen = false;

			return false;
		}

		//* Closing Files *//
		// setting the content of the output file to the main file
		char c2;
		Logger::Log("setting the content of the output file to the main file", Logger::LogType::DEBUG);
		while (!fin.eof())
		{
			fin >> std::noskipws >> c2;
			m_file << (char)c2;
		}
		Logger::Log("File encrypted", Logger::LogType::INFO);

		// closing the output file
		try
		{
			fin.close();
		}
		catch (std::exception& e)
		{
			Logger::Log(
				std::format("Error:\n    the file: '{}' can't be closed", m_path),
				Logger::LogType::ERROR);
			m_isOpen = true;

			return false;
		}

		// deleting the output file
		try
		{
			remove("temp.txt");
		}
		catch (std::exception& e)
		{
			Logger::Log(
				std::format("Error:\n    the file: '{}' can't be deleted", "temp.txt"),
				Logger::LogType::ERROR);
			m_isOpen = true;

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
			Logger::Log(
				std::format("Error:\n    the file: '{}' can't be closed", m_path),
				Logger::LogType::ERROR);
			m_isOpen = true;

			return false;
		}

		if (wasOpen)
		{
			Logger::Log("file was open, opening it again", Logger::LogType::DEBUG);
			Open();
		}

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
		
		Logger::Log("Deleting the file", Logger::LogType::INFO);
		
		try
		{
			remove(m_path.c_str());
		}
		catch (std::exception& e)
		{
			Logger::Log(std::format("Error:\n    the file: '{}' can't be deleted", m_path), Logger::LogType::ERROR);
			return false;
		}
		Logger::Log("File deleted", Logger::LogType::INFO);
		
		return true;
	}
}