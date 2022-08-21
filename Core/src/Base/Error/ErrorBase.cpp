#include "ErrorBase.h"

#include <format>

namespace Core
{
    namespace Error
    {
        Base::Base(std::string Error, std::string Description, std::string FullDescription = "", std::string File, std::string Function, std::string ErrorLogFilePath = "Log.log")
        {
            
        }

        Base::~Base()
        {
        }

        std::string Base::ToString()
        {
            return std::format(
                m_Message,
                Error,
                FilePath,
                Line,
                Function,
                Description,
                ErrorLogFilePath
            );
        }

        std::string Base::FullString()
        {
            return std::format(
                m_Message,
                Error,
                FullDescription,
                FilePath,
                Line,
                Function,
                ErrorLogFilePath
            );
        }
    }
}