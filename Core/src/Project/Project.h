#pragma once

#include <string>

#include "src/Project/ProjectType.h"
#include "src/FileManagment/ProjectFile.h"

namespace Core
{
	namespace ProjectNS
	{
		class Project
		{
		public:
			Project(std::string name, std::string description, class ProjectType projectType);
			~Project();

			void Load();
			void Save();
			void Close();
			void SaveAndClose();

			void SetName(std::string name);
			void SetDescription(std::string description);

			bool IsLoaded();
			bool IsSaved();
			bool IsClosed();
			bool IsExist();
			bool IsEdited();


		private:
			// project type
			class ProjectType m_ProjectType;
			class ProjectType m_ProjectTypeCategory;

			// project file
			ProjectFile m_ProjectFile;

			// string data
			std::string m_Name;
			std::string m_Description;
			std::string m_Path;
			std::string version;

			// int data
			int m_Id;

			// bool data
			bool m_IsLoaded;
			bool m_IsSaved;
			bool m_IsEdited;
		};
	}
}