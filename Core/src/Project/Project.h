#pragma once

#include <string>

#include "src/Project/ProjectType.h"

namespace Core
{
	namespace Project
	{
		class Project
		{
		public:
			Project(std::string name, std::string description, _ProjectType projectType);
			~Project();

			void Load();
			void Save();
			void Close();

			void SetName(std::string name);
			void SetDescription(std::string description);

			bool IsLoaded();
			bool IsSaved();
			bool IsClosed();
			bool IsExist();
			bool IsEdited();


		private:
			// project type
			_ProjectType m_ProjectType;
			_ProjectType m_ProjectTypeCategory;

			// project file
			//ProjectFile m_ProjectFile;

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
			bool m_IsClosed;
			bool m_IsExist;
			bool m_IsEdited;
		};
	}
}