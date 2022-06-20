#pragma once

#include <fstream>
#include <string>

namespace Oort
{
	class OortFile
	{
	public:
		// Constructor & Destructor
		OortFile(const std::string path);
		~OortFile();

		// Main Functions
		bool Open();
		bool Close();

		// Read & Write Functions
		std::string Read();
		bool Write(const std::string str);

		// Cartography Functions
		bool Encrypt(const int key = 0);
		bool Decrypt(const int key = 0);

		// Check Parameters
		bool IsOpen();
		bool IsExists();
		bool IsReadable();
		bool IsWritable();
		
		// Get Parameters
		std::string GetPath();
		std::string GetName();
		std::string GetExtension();
		std::string GetFullName();
		
	private:
		std::string m_path;
		std::string m_name;
		std::string m_extension;
		std::string m_fullName;
		
		std::fstream m_file;
		std::fstream m_temp;

		bool m_isOpen;
		bool m_isExists;
		bool m_isReadable;
		bool m_isWritable;
		
		int m_key;
	};
}
