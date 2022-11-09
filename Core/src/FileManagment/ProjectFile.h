#pragma once

#include "src/Base/FileManagment/Basic_File.h"
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

		std::any GetProjectName();
		std::any GetProjectPath();
		std::any GetProjectFilePath();
		std::any GetCreationDate();
		std::any GetLastModifiedDate();
		std::any GetProjectDescription();
		std::any GetProjectAuthor();
		std::any GetProjectVersion();
		std::any GetProjectLicense();
		std::any GetProjectWebsite();
		std::any GetProjectEmail();
		std::any GetProjectPhone();
		std::any GetProjectType();
		
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