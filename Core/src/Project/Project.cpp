#include "Project.h"

#include <string>

using std::string;

namespace Core
{
    namespace Project
    {
        Project::Project(std::string name, std::string description, ProjectType projectType) :
            m_ProjectFile("src/Project/" + name + ".project")
        {
            m_Name = name;
            m_Description = description;
            m_ProjectType = projectType;
        }

        Project::~Project()
        {
        }
		
        void Project::Load()
        {
        }
		
        void Project::Save()
        {
        }
		
        void Project::Close()
        {
        }
		
        void Project::SetName(std::string name)
        {
        }
		
        void Project::SetDescription(std::string description)
        {
        }
		
        bool Project::IsLoaded()
        {
            return false;
        }
		
        bool Project::IsSaved()
        {
            return false;
        }
		
        bool Project::IsClosed()
        {
            return false;
        }
		
        bool Project::IsExist()
        {
            return false;
        }
		
        bool Project::IsEdited()
        {
            return false;
        }
    }
}