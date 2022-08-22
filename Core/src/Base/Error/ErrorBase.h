#pragma once

#include "src/Base/FileManagment/Basic_File.h"

#include <string>
#include <exception>

namespace Core
{
    namespace Error
    {
        class Base : public std::exception
        {
            // (Con/De)structors
            Base(
                std::string Error,
                std::string Description,
                std::string FilePath,
                std::string Function,
                std::string FullDescription = "",
                std::string ErrorLogFilePath = "Log.log"
            );
            ~Base();

        public:
            std::string ToString();
            std::string FullString();

            virtual void what();

        private:
            //File m_ErrorLogFile;

        public:
            std::string m_Error;
            std::string m_Description;
            std::string m_FullDescription;

            std::string m_FilePath;
            std::string m_Function;

            std::string m_ErrorLogFilePath;

            int m_Line;
        };
    }
}
