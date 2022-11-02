#pragma once

#include "src/Base/FileManagment/Basic_File.h"
#include "src/Base/Time/Time.h"
#include <string>                                                                      
#include <map>

namespace Core
{
	class ProjectFile : File
	{
	public:
		ProjectFile(const std::string file_path);
		~ProjectFile();

		void Load();
		void Reload();
		void Save();

		std::string GetProjectName();
		std::string GetProjectPath();
		std::string GetProjectFilePath();
		std::string GetCreationDate();
		std::string GetLastModifiedDate();
		std::string GetProjectDescription();
		std::string GetProjectAuthor();
		std::string GetProjectVersion();
		std::string GetProjectLicense();
		std::string GetProjectWebsite();
		std::string GetProjectEmail();
		std::string GetProjectPhone();
		std::string GetProjectType();
		
		std::string SetProjectName(std::string name);
		std::string SetProjectPath(std::string path);
		std::string SetProjectFilePath(std::string path);
		std::string SetCreationDate(Time::Date date);
		std::string SetLastModifiedDate(Time::Date date);
		std::string SetProjectDescription(std::string);
		std::string SetProjectAuthor(std::string);
		std::string SetProjectVersion(std::string);
		std::string SetProjectLicense();
		std::string SetProjectWebsite();
		std::string SetProjectEmail(std::string);
		std::string SetProjectPhone(std::string);
		std::string SetProjectType(Project::ProjectType);
	
	private:
		std::map<std::string, std::string> projectData;
	};
}