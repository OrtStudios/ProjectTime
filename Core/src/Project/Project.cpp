#include "Project.h"

#include <string>

using std::string;

namespace Core
{
    namespace Project
    {
        Project::Project(std::string name, std::string description, _ProjectType projectType)
        {
            m_Name = name;
            m_Description = description;
            m_ProjectType = projectType;

            //m_ProjectFile = ProjectFile(
            //    "src/Project/" + m_Name + ".project"
            //);
        }

        Project::~Project()
        {
            //delete &m_ProjectFile;
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