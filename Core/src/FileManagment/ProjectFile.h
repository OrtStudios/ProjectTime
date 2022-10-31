#pragma once

#include "src/Base/FileManagment/Basic_File.h"
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
	
	private:
		std::map<std::string, std::string> projectData;
	};
}