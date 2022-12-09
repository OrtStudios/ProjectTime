#include "ProjectFile.h"

#include <string>
#include <vector>
#include <typeinfo>
#include <src/Base/Logger.h>
#include <src/Base/Types/StringFunc.h>

using std::string;
using std::any;

namespace Core
{
	ProjectFile::ProjectFile(const string file_path) : File(file_path)
	{
	}

	ProjectFile::~ProjectFile()
	{
		Close();
	}
	
	// Load & Reload
	void ProjectFile::Load()
	{
		// load file
		Open();
	
		// get file data
		string fileData = Read();

		// close file
		Close();
	
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
				Logger::Log("Loaded: " + lineData[0] + " = " + lineData[1], Logger::LogType::DEBUG);
			}
		}
		
		// Log the project data
		Logger::Log("Loading project data", Logger::LogType::INFO);
		for (auto const& x : projectData)
		{
			if (typeid(x.second) == typeid(string))
				Logger::Log(x.first + " = " + std::any_cast<string>(x.second), Logger::LogType::DEBUG);

		}
	}
	
	void ProjectFile::Reload()
	{
		// clear map
		projectData.clear();
		Logger::Log("Project file cleared", Logger::LogType::DEBUG);
	
		// reload file
		Load();
		Logger::Log("Project file reloaded", Logger::LogType::INFO);
	}
	
	void ProjectFile::Save()
	{
		// get the file data and create a string from it
		string fileData = "";
		SaveMap(fileData);

		// clear the file and write the data to it
		Open();
		Clear();
		Write(fileData);
		Close();
		Logger::Log("Project file saved", Logger::LogType::INFO);
	}

	void ProjectFile::SaveMap(std::string fileData, std::map<string, any> data)
	{
		if (data.empty())
		{
			data == projectData;
		}

		for (auto const& x : projectData)
		{
			if (typeid(x.second) == typeid(string))
			{
				fileData += x.first + "=" + std::any_cast<string>(x.second) + "\n";
				Logger::Log(x.first + " = " + std::any_cast<string>(x.second) + "|Loaded", Logger::LogType::DEBUG);
			}
			else if (typeid(x.second) == typeid(std::map<string, any>))
			{
				
				SaveMap(fileData, std::any_cast<std::map<string, any>>(x.second));
			}

		}
	}

	// Getters
	string ProjectFile::GetProjectName()
	{
		return std::any_cast<string>(projectData["name"]);
	}
	
	string ProjectFile::GetProjectPath()
	{
		return std::any_cast<string>(projectData["path"]);
	}
	
	string ProjectFile::GetProjectFilePath()
	{
		return std::any_cast<string>(projectData["file_path"]);
	}
	
	string ProjectFile::GetCreationDate()
	{
		return std::any_cast<string>(projectData["creation_date"]);
	}
	
	string ProjectFile::GetLastModifiedDate()
	{
		return std::any_cast<string>(projectData["last_modified_date"]);
	}
	
	string ProjectFile::GetProjectDescription()
	{
		return std::any_cast<string>(projectData["description"]);
	}
	
	string ProjectFile::GetProjectAuthor()
	{
		return std::any_cast<string>(projectData["author"]);
	}
	
	string ProjectFile::GetProjectVersion()
	{
		return std::any_cast<string>(projectData["version"]);
	}
	
	string ProjectFile::GetProjectLicense()
	{
		return std::any_cast<string>(projectData["license"]);
	}
	
	string ProjectFile::GetProjectWebsite()
	{
		return std::any_cast<string>(projectData["website"]);
	}
	
	string ProjectFile::GetProjectEmail()
	{
		return std::any_cast<string>(projectData["email"]);
	}
	
	string ProjectFile::GetProjectPhone()
	{
		return std::any_cast<string>(projectData["phone"]);
	}
	
	string ProjectFile::GetProjectType()
	{
		return std::any_cast<string>(projectData["type"]);
	}

	// Setters
	void ProjectFile::SetProjectName(string name)
	{
		projectData["name"] = name;
		Logger::Log("Project name set to " + name, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectPath(string path)
	{
		projectData["path"] = path;
		Logger::Log("Project path set to " + path, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectFilePath(string file_path)
	{
		projectData["file_path"] = file_path;
		Logger::Log("Project file path set to " + file_path, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetCreationDate(Time::Date creation_date)
	{
		projectData["creation_date"] = creation_date;
		Logger::Log("Project creation date set to " + creation_date.GetDate(), Logger::LogType::DEBUG);
	}

	void ProjectFile::SetLastModifiedDate(Time::Date last_modified_date)
	{
		projectData["last_modified_date"] = last_modified_date;
		Logger::Log("Project last modified date set to " + last_modified_date.GetDate(), Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectDescription(string description)
	{
		projectData["description"] = description;
		Logger::Log("Project description set to " + description, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectAuthor(string author)
	{
		projectData["author"] = author;
		Logger::Log("Project author set to " + author, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectVersion(string version)
	{
		projectData["version"] = version;
		Logger::Log("Project version set to " + version, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectLicense(File license)
	{
		projectData["license"] = license.GetPath();
		Logger::Log("Project license set to " + license.GetName(), Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectWebsite(Url website)
	{
		projectData["website"] = website;
		Logger::Log("Project website set to " + website.GetDomain(), Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectEmail(string email)
	{
		projectData["email"] = email;
		Logger::Log("Project email set to " + email, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectType(ProjectNS::ProjectType type)
	{
		projectData["type"] = type;
		Logger::Log("Project type set to " + type.ToString(), Logger::LogType::DEBUG);
	}
}