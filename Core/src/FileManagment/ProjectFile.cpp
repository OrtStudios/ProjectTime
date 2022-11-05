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
			Logger::Log(x.first + " = " + x.second, Logger::LogType::DEBUG);
		}

		// set loaded
		loaded = true;
		Logger::Log("Project file loaded", Logger::LogType::INFO);
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
		for (auto const& x : projectData)
		{
			fileData += x.first + "=" + x.second + "\n";
			Logger::Log(x.first + " = " + x.second + "|Loaded", Logger::LogType::DEBUG);
		}

		// clear the file and write the data to it
		Open();
		Clear();
		Write(fileData);
		Close();
		Logger::Log("Project file saved", Logger::LogType::INFO);
	}

	// Getters
	string ProjectFile::GetProjectName()
	{
		return projectData["name"];
	}
	
	string ProjectFile::GetProjectPath()
	{
		return projectData["path"];
	}
	
	string ProjectFile::GetProjectFilePath()
	{
		return projectData["file_path"];
	}
	
	string ProjectFile::GetCreationDate()
	{
		return projectData["creation_date"];
	}
	
	string ProjectFile::GetLastModifiedDate()
	{
		return projectData["last_modified_date"];
	}
	
	string ProjectFile::GetProjectDescription()
	{
		return projectData["description"];
	}
	
	string ProjectFile::GetProjectAuthor()
	{
		return projectData["author"];
	}
	
	string ProjectFile::GetProjectVersion()
	{
		return projectData["version"];
	}
	
	string ProjectFile::GetProjectLicense()
	{
		return projectData["license"];
	}
	
	string ProjectFile::GetProjectWebsite()
	{
		return projectData["website"];
	}
	
	string ProjectFile::GetProjectEmail()
	{
		return projectData["email"];
	}
	string ProjectFile::GetProjectPhone()
	{
		return projectData["phone"];
	}
	
	string ProjectFile::GetProjectType()
	{
		return projectData["type"];
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

	void ProjectFile::SetCreationDate(Date creation_date)
	{
		projectData["creation_date"] = creation_date;
		Logger::Log("Project creation date set to " + creation_date, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetLastModifiedDate(Date last_modified_date)
	{
		projectData["last_modified_date"] = last_modified_date;
		Logger::Log("Project last modified date set to " + last_modified_date, Logger::LogType::DEBUG);
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
		projectData["license"] = license;
		Logger::Log("Project license set to " + license, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectWebsite(Url website)
	{
		projectData["website"] = website;
		Logger::Log("Project website set to " + website, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectEmail(string email)
	{
		projectData["email"] = email;
		Logger::Log("Project email set to " + email, Logger::LogType::DEBUG);
	}

	void ProjectFile::SetProjectType(ProjectType type)
	{
		projectData["type"] = type;
		Logger::Log("Project type set to " + type, Logger::LogType::DEBUG);
	}
}