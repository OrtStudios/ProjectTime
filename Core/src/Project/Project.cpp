#include "Project.h"

#include <string>

#include "src/Project/ProjectType.h"

using std::string;

namespace Core
{
    namespace Project
    {
        Project::Project(std::string name, std::string description, class ProjectType projectType)
        {
            m_Name = name;
            m_Description = description;
            m_ProjectType = projectType;

            m_ProjectFile = ProjectFile(
                "src/Project/" + m_Name + ".project"
            );
        }

        Project::~Project()
        {
            delete m_ProjectFile;
        }
    }
}