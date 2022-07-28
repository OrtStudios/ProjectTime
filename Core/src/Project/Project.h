#pragma once

#include <string>

#include "src/Project/ProjectType.h"

namespace Core
{

	class Project
	{
	public:
		Project(
			std::string name,
			int id,
			std::string description,
			BaseProjectType projectType
		);
		~Project();

		void Load();
		void Save();
		void Close();

	private:
		BaseProjectType m_projectType;
		BaseProjectType m_projectTypeCategory;
	};
}