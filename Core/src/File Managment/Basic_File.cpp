#include "pch.h"
#include "Basic_File.h"

#include <iostream>
#include <string>
#include <fstream>
#include <format>

using std::string;

namespace Oort
{
	// Private functions
	string OortFile::m_GetFullName(const string path)
	{
		size_t lastSlash = path.find_last_of("/");

		if (lastSlash == std::string::npos)
		{
			lastSlash = path.find_last_of("\\");
		}
		else
		{
			throw std::invalid_argument(std::format("Error:\n    the file path: '{}' is invalid", path));
		}

		return path.substr(lastSlash);
	}

	// Constructor & Destructor
	OortFile::OortFile(const string path)
	{
		m_file = std::fstream(path);

		m_fullName = m_GetFullName(path);
	}
	
	OortFile::~OortFile()
	{
		delete &m_file;
	}

	// Main Functions
	bool OortFile::Open()
	{
		return false;
	}

	bool OortFile::Close()
	{
		return false;
	}

	// Read & Write Functions
	string OortFile::Read()
	{
		return string();
	}
	
	bool OortFile::Write(const string str)
	{
		return false;
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
		return false;
	}

	bool OortFile::IsExists()
	{
		return false;
	}

	bool OortFile::IsReadable()
	{
		return false;
	}

	bool OortFile::IsWritable()
	{
		return false;
	}

	// Get Parameters
	string OortFile::GetPath()
	{
		return string();
	}

	string OortFile::GetName()
	{
		return string();
	}

	string OortFile::GetExtension()
	{
		return string();
	}

	string OortFile::GetFullName()
	{
		return string();
	}
}
