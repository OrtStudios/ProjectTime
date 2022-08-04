#include "ProjectFile.h"

#include <string>

using std::string;

namespace Core
{
	// Constructor & Destructor
	ProjectFile::ProjectFile(const string file_path) : File(file_path)
	{
	}

	ProjectFile::~ProjectFile()
	{
	}
	
	// Load & Reload
	void ProjectFile::Load()
	{
	}
	
	void ProjectFile::Reload()
	{
	}
	
	// Getters
	string ProjectFile::GetProjectName()
	{
		return "";
	}
	
	string ProjectFile::GetProjectPath()
	{
		return std::string();
	}
	
	string ProjectFile::GetProjectFilePath()
	{
		return std::string();
	}
	
	string ProjectFile::GetCreationDate()
	{
		return std::string();
	}
	
	string ProjectFile::GetLastModifiedDate()
	{
		return std::string();
	}
	
	string ProjectFile::GetProjectDescription()
	{
		return std::string();
	}
	
	string ProjectFile::GetProjectAuthor()
	{
		return std::string();
	}
	
	string ProjectFile::GetProjectVersion()
	{
		return std::string();
	}
	
	string ProjectFile::GetProjectLicense()
	{
		return std::string();
	}
	
	string ProjectFile::GetProjectWebsite()
	{
		return std::string();
	}
	
	string ProjectFile::GetProjectEmail()
	{
		return string();
	}
	string ProjectFile::GetProjectPhone()
	{
		return string();
	}
	
	string ProjectFile::GetProjectType()
	{
		return string();
	}
}