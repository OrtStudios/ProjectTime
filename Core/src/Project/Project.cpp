#include "Project.h"

#include <string>

#include "src/Base/Logger.h"

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
			delete& m_ProjectFile;
			Logger::Log("Project file deleted", Logger::LogType::DEBUG);
        }
		
        void Project::Load()
        {
			// check if project is loaded
			if (m_IsLoaded)
			{
				Logger::Log("Project is already loaded!", Logger::LogType::WARNING); // log warning
				return;
			}
			
			// if the project is not loaded
			// load the project file
			m_ProjectFile.Load();

			// set project info from project file
			m_Name = m_ProjectFile.GetProjectName();
			m_Description = m_ProjectFile.GetProjectDescription();
			m_Path = m_ProjectFile.GetProjectPath();
			
			// set the project as loaded
            m_IsLoaded = true;
			Logger::Log("Project " + m_Name + " loaded", Logger::LogType::INFO); // log info
        }
		
        void Project::Save()
        {
			// check if project is saved
            if (m_IsSaved)
            {
                Logger::Log("Project is already saved!", Logger::LogType::WARNING); // log warning
                return;
            }

			// set the updated parameters to the project file
			m_ProjectFile.GetLastModifiedDate

			// if the project is not saved
			// save the project file
			m_ProjectFile.Save();
			
			// set the project as saved
			m_IsSaved = true;
			Logger::Log("Project " + m_Name + " saved", Logger::LogType::INFO); // log info
        }
		
        void Project::Close()
        {
			// deactivaite the project		
			delete this;
        }

        void Project::SaveAndClose()
        {
            /// <summary>
			/// saves the project and closes it
            /// </summary>
            Save();
            Close();
        }
		
        void Project::SetName(std::string name)
        {
			m_Name = name;
        }
		
        void Project::SetDescription(std::string description)
        {
        }
		
        bool Project::IsLoaded()
        {
			/// <summary>
			/// returns if the project is loaded
			/// </summary>
			/// <returns> if the project is loaded </returns>
			return m_IsLoaded;
		}
		
        bool Project::IsSaved()
        {
			/// <summary>
			/// returns if the project is saved
			/// </summary>
			/// <returns> if the project is saved </returns>
			return m_IsSaved;
        }
		
        bool Project::IsEdited()
        {
			/// <summary>
			/// returns if the project is edited
			/// </summary>
			/// <returns> if the project is edited </returns>
			return m_IsEdited;
        }
    }
}