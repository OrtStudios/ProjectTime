#include "ErrorBase.h"

#include <format>

namespace Core
{
    namespace Error
    {
        Base::Base(std::string Error, std::string Description, std::string FullDescription = "", std::string FilePath, std::string Function, std::string ErrorLogFilePath = "Log.log")
        {
            // set vars
            m_Error = Error;
            m_Description = Description;
            m_FullDescription = FullDescription;
            m_FilePath = FilePath;
            m_Function = Function;
            m_ErrorLogFilePath = ErrorLogFilePath;

            // create the log file
            m_ErrorLogFile = File(m_ErrorLogFilePath);
        }

        Base::~Base()
        {
            delete &m_ErrorLogFile;
        }

        std::string Base::ToString()
        {
            return std::format(
                m_Message,
                m_Error,
                m_FilePath,
                m_Line,
                m_Function,
                m_Description,
                m_ErrorLogFilePath
            );
        }

        std::string Base::FullString()
        {
            return std::format(
                m_Message,
                m_Error,
                m_FullDescription,
                m_FilePath,
                m_Line,
                m_Function,
                m_ErrorLogFilePath
            );
        }
    }
}