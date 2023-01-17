#pragma once

#include "src/FileManagment/DataFile.h"
#include "src/Project/ProjectType.h"
#include "src/Time/Time.h"
#include "src/Types/Url.h"
#include <string>                                                                      
#include <map>
#include <any>

namespace Core
{
	class ProjectFile : DataFile
	{
	public:
		ProjectFile(const std::string file_path);
		~ProjectFile();

		void Reload();

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
	};
}