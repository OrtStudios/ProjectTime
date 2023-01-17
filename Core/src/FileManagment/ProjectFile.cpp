#include "ProjectFile.h"

#include <string>
#include <vector>
#include <typeinfo>

#include "src/Logger.h"
#include "src/Types/StringFunc.h"

using std::string;
using std::any;

namespace Core
{
	ProjectFile::ProjectFile(const string file_path) : DataFile(file_path)
	{
	}

	ProjectFile::~ProjectFile()
	{
		Close();
	}
	
	void ProjectFile::Reload()
	{
		// clear map
		GetData().clear();
		Logger::Log("Project file cleared", Logger::LogType::DEBUG);
	
		// reload file
		Load();
		Logger::Log("Project file reloaded", Logger::LogType::INFO);
	}

	// Getters
	string ProjectFile::GetProjectName()
	{
		return std::any_cast<string>(GetData()["name"]);
	}
	
	string ProjectFile::GetProjectPath()
	{
		return std::any_cast<string>(GetData()["path"]);
	}
	
	string ProjectFile::GetProjectFilePath()
	{
		return std::any_cast<string>(GetData()["file_path"]);
	}
	
	string ProjectFile::GetCreationDate()
	{
		return std::any_cast<string>(GetData()["creation_date"]);
	}
	
	string ProjectFile::GetLastModifiedDate()
	{
		return std::any_cast<string>(GetData()["last_modified_date"]);
	}
	
	string ProjectFile::GetProjectDescription()
	{
		return std::any_cast<string>(GetData()["description"]);
	}
	
	string ProjectFile::GetProjectAuthor()
	{
		return std::any_cast<string>(GetData()["author"]);
	}
	
	string ProjectFile::GetProjectVersion()
	{
		return std::any_cast<string>(GetData()["version"]);
	}
	
	string ProjectFile::GetProjectLicense()
	{
		return std::any_cast<string>(GetData()["license"]);
	}
	
	string ProjectFile::GetProjectWebsite()
	{
		return std::any_cast<string>(GetData()["website"]);
	}
	
	string ProjectFile::GetProjectEmail()
	{
		return std::any_cast<string>(GetData()["email"]);
	}
	
	string ProjectFile::GetProjectPhone()
	{
		return std::any_cast<string>(GetData()["phone"]);
	}
	
	string ProjectFile::GetProjectType()
	{
		return std::any_cast<string>(GetData()["type"]);
	}

	// Setters
	void ProjectFile::SetProjectName(string name)
	{
		GetData()["name"].SetString(name);
		Logger::Log("Project name set to " + name, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectPath(string path)
	{
		GetData()["path"].SetString(path);
		Logger::Log("Project path set to " + path, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectFilePath(string file_path)
	{
		GetData()["file_path"].SetString(file_path);
		Logger::Log("Project file path set to " + file_path, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetCreationDate(Time::Date creation_date)
	{
		GetData()["creation_date"].SetString(creation_date.GetDate());
		Logger::Log("Project creation date set to " + creation_date.GetDate(), Logger::LogType::DEBUG);
	}

	void ProjectFile::SetLastModifiedDate(Time::Date last_modified_date)
	{
		GetData()["last_modified_date"].SetString(last_modified_date.GetDate());
		Logger::Log("Project last modified date set to " + last_modified_date.GetDate(), Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectDescription(string description)
	{
		GetData()["description"].SetString(description);
		Logger::Log("Project description set to " + description, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectAuthor(string author)
	{
		GetData()["author"].SetString(author);
		Logger::Log("Project author set to " + author, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectVersion(string version)
	{
		GetData()["version"].SetString(version);
		Logger::Log("Project version set to " + version, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectLicense(File license)
	{
		GetData()["license"]["name"].SetString(license.GetName());
		GetData()["license"]["file_path"].SetString(license.GetPath());
		Logger::Log("Project license set to " + license.GetName(), Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectWebsite(Url website)
	{
		GetData()["website"].SetString(website.GetUrl());
		Logger::Log("Project website set to " + website.GetDomain(), Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectEmail(string email)
	{
		GetData()["email"].SetString(email);
		Logger::Log("Project email set to " + email, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectType(ProjectNS::ProjectType type)
	{
		GetData()["type"].SetString(type.ToString());
		Logger::Log("Project type set to " + type.ToString(), Logger::LogType::DEBUG);
	}
}