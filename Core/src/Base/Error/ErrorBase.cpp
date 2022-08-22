#include "ErrorBase.h"

#include "src/Base/Logger.h"

#include <format>

namespace Core
{
    namespace Error
    {
        Base::Base(
            std::string Error,
            std::string Description,
            std::string FilePath,
            std::string Function, 
            std::string FullDescription, 
            std::string ErrorLogFilePath)
        {
            // set vars
            m_Error = Error;
            m_Description = Description;
            m_FullDescription = FullDescription;
            m_FilePath = FilePath;
            m_Function = Function;
            m_ErrorLogFilePath = ErrorLogFilePath;

            // create the log file
            //m_ErrorLogFile = File(m_ErrorLogFilePath);
        }

        Base::~Base()
        {
            //delete &m_ErrorLogFile;
        }

        std::string Base::ToString()
        {
            return std::format(
                "a {} has ocurred:\n\tfile : {}\n\tline : {}\n\tfunc : {}\n\treason : {}\nfor full info go to : {}",
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
                "a {} has ocurred:\n\tERROR:\n\t\t{}\n\tWHERE:\n\t\tfile: {}\n\t\tline: {}\n\t\tfunc: {}\n\t\tlog file: {}",
                m_Error,
                m_FullDescription,
                m_FilePath,
                m_Line,
                m_Function,
                m_ErrorLogFilePath
            );
        }

        void Base::what()
        {
            Logger().Log(ToString());
            return;
;        }
    }
}