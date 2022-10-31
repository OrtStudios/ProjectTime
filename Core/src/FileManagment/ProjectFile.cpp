#include "ProjectFile.h"

#include <string>
#include <vector>
#include <src/Base/Logger.h>
#include <src/Base/String/StringFunc.h>

using std::string;

namespace Core
{
	ProjectFile::ProjectFile(const string file_path) : File(file_path)
	{
	}

	ProjectFile::~ProjectFile()
	{
	}
	
	// Load & Reload
	void ProjectFile::Load()
	{
		// load file
		Open();
	
		// get file data
		string fileData = Read();
	
		// split file data
		std::vector<string> fileDataSplitted = StringFunc::Split(fileData, '\n');
	
		// iterate through file data
		for (int i = 0; i < fileDataSplitted.size(); i++)
		{
			// split line
			std::vector<string> lineData = StringFunc::Split(fileDataSplitted[i], '=');
	
			// check if line is valid
			if (lineData.size() == 2)
			{
				// add line data to map
				projectData[lineData[0]] = lineData[1];
			}
		}
		
		// Log the project data
		Logger::Log("Project file loaded", Logger::LogType::INFO);
		for (auto const& x : projectData)
		{
			Logger::Log(x.first + " = " + x.second, Logger::LogType::DEBUG);
		}
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