#pragma once

#include "src/Base/FileManagment/Basic_File.h"

#include <string>

namespace Core
{
    namespace Error
    {
        class Base
        {
            // (Con/De)structors
            Base(
                std::string Error,
                std::string Description,
                std::string FullDescription = "",
                std::string FilePath,
                std::string Function,
                std::string ErrorLogFilePath = "Log.log"
            );
            ~Base();

        public:
            std::string ToString();
            std::string FullString();

        private:
            std::string m_Message = "a {} has ocurred:\n\tfile : {}\n\tline : {}\n\tfunc : {}\n\treason : {}\nfor full info go to : {}";
            std::string m_FullMessage = "a {} has ocurred:\n\tERROR:\n\t\t{}\n\tWHERE:\n\t\tfile: {}\n\t\tline: {}\n\t\tfunc: {}\n\t\tlog file: {}";

            File m_ErrorLogFile;

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
