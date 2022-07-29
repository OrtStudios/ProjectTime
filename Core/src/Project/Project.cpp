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
        }
    }
}