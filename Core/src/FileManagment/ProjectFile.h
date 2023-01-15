#pragma once

#include "src/Base/FileManagment/BasicFile.h"
#include "src/Project/ProjectType.h"
#include "src/Base/Time/Time.h"
#include "src/Base/Types/Url.h"
#include <string>                                                                      
#include <map>
#include <any>

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

		void SaveMap(std::string fileData, std::map<std::string, std::any> data = {});

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
		
		void SetProjectName(std::string name);
		void SetProjectPath(std::string path);
		void SetProjectFilePath(std::string path);
		void SetCreationDate(Time::Date date);
		void SetLastModifiedDate(Time::Date date);
		void SetProjectDescription(std::string);
		void SetProjectAuthor(std::string);
		void SetProjectVersion(std::string);
		void SetProjectLicense(File licence);
		void SetProjectWebsite(Url website);
		void SetProjectEmail(std::string);
		void SetProjectType(ProjectNS::ProjectType);
	
	private:
		std::map<std::string, std::any> projectData;
	};
}