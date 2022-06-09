#pragma once

#include "../Core/src/Logger.h"

namespace Oort 
{
	public enum class LogType
	{
		LOG_TYPE_DEBUG = 0,
		LOG_TYPE_INFO = 1,
		LOG_TYPE_WARNING = 2,
		LOG_TYPE_ERROR = 3,
		LOG_TYPE_FATAL = 4,
		LOG_TYPE_MASTER = 5
	};
	
	public ref class OortMain
	{
	public:	
		OortMain();
		~OortMain();

		void Log(System::String^ message, LogType level);
		
	private:
		Logger *logger;
	};
}
