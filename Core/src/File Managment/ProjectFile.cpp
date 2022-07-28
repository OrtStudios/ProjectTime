#include "pch.h"
#include "ProjectFile.h"

#include <string>

using std::string;

namespace Core
{
	// Constructor & Destructor
	ProjectFile::ProjectFile(const string file_path) : File(file_path, "r")
	{
	}

	ProjectFile::~ProjectFile()
	{
	}
	
	// Load & Reload
	void ProjectFile::Load()
	{
	}
	
	void ProjectFile::Reload()
	{
	}
	
	// Getters
	string ProjectFile::GetProjectName()
	{
		return "";
	}
}