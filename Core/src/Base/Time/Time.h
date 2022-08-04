#pragma once

#include <chrono>

namespace Core
{
	namespace Time
	{
		auto GetTime()
		{
			return std::chrono::high_resolution_clock::now();
		}
	}
}