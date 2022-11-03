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
		// clear map
		projectData.clear();
	
		// reload file
		Load();
	}
	
	void ProjectFile::Save()
	{
		// get the file data and create a string from it
		string fileData = "";
		for (auto const& x : projectData)
		{
			fileData += x.first + "=" + x.second + "\n";
		}

		// clear the file and write the data to it
		Open();
		Clear();
		Write(fileData);
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
	}

	void ProjectFile::SetProjectPath(string path)
	{
		projectData["path"] = path;
	}

	void ProjectFile::SetProjectFilePath(string file_path)
	{
		projectData["file_path"] = file_path;
	}

	void ProjectFile::SetCreationDate(Date creation_date)
	{
		projectData["creation_date"] = creation_date;
	}

	void ProjectFile::SetLastModifiedDate(Date last_modified_date)
	{
		projectData["last_modified_date"] = last_modified_date;
	}

	void ProjectFile::SetProjectDescription(string description)
	{
		projectData["description"] = description;
	}

	void ProjectFile::SetProjectAuthor(string author)
	{
		projectData["author"] = author;
	}

	void ProjectFile::SetProjectVersion(string version)
	{
		projectData["version"] = version;
	}

	void ProjectFile::SetProjectLicense(File license)
	{
		projectData["license"] = license;
	}

	void ProjectFile::SetProjectWebsite(Url website)
	{
		projectData["website"] = website;
	}

	void ProjectFile::SetProjectEmail(string email)
	{
		projectData["email"] = email;
	}

	void ProjectFile::SetProjectType(ProjectType type)
	{
		projectData["type"] = type;
	}
}