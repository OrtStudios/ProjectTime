#pragma once

#include <fstream>
#include <string>

namespace Core
{
	class File
	{
	private:
		std::string* m_GetFullName(const std::string path);

	public:
		// Constructor & Destructor
		File(const std::string path);
		~File();

		// Main Functions
		bool Open();
		bool Close();
		bool Save();

		// Read & Write Functions
		std::string Read();
		bool Write(const std::string str);
		bool Clear();

		// Cartography Functions
		bool Encrypt(const int key = 0);
		bool Decrypt(const int key = 0);

		// Check Parameters
		bool IsOpen();
		bool IsExists();
		bool IsReadable();
		bool IsWritable();

		// Delete File
		bool Delete();
		
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
	};
}
