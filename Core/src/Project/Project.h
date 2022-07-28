#pragma once

#include <string>

#include "src/Project/ProjectType.h"

namespace Core
{

	class Project
	{
	public:
		Project();
		~Project();

		void Load();
		void Save();
		void Close();

	private:
		BaseProjectType projectType;
	};
}