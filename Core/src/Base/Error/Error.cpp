#include "Error.h"

#include "src/Base/Logger.h"
#include "rang.hpp"

#include <format>
#include <iostream>

using std::string;
using std::cout;
using std::format;

namespace Core
{
    namespace Error
    {
        Base::Base(
            string Error,
            string Description,
            string FullDescription, 
            string ErrorLogFilePath)
        {
            // set vars
            m_Error = Error;
            m_Description = Description;
            m_FullDescription = FullDescription;
            m_ErrorLogFilePath = ErrorLogFilePath;

            // create the log file
            //m_ErrorLogFile = File(m_ErrorLogFilePath);
        }

        Base::~Base()
        {
            //delete &m_ErrorLogFile;
        }

        string Base::ToString()
        {
            // get file
            m_FilePath = __FILE__;
            m_Line = __LINE__;
            m_Function = __func__;

            return format(
                "a {} has ocurred:\n\tfile: {}\n\tline: {}\n\tfunc: {}\n\treason: {}\nfor full info go to: {}",
                m_Error,
                m_FilePath,
                m_Line,
                m_Function,
                m_Description,
                m_ErrorLogFilePath
            );
        }

        string Base::FullString()
        {
            // get file
            m_FilePath = __FILE__;
            m_Line = __LINE__;
            m_Function = __func__;

            return format(
                "a {} has ocurred:\n\tERROR:\n\t\t{}\n\tWHERE:\n\t\tfile: {}\n\t\tline: {}\n\t\tfunc: {}\n\t\tlog file: {}",
                m_Error,
                m_FullDescription,
                m_FilePath,
                m_Line,
                m_Function,
                m_ErrorLogFilePath
            );
        }

        string Base::what()
        {
            // get file
            m_FilePath = __FILE__;
            m_Line = __LINE__;
            m_Function = __func__;

            //* Print's the ERROR message to the console
            cout << rang::fgB::red << rang::style::bold << format("a {} has ocurred:", m_Error) 
                << "\n";
            cout << rang::fgB::green << "\tfile: " 
                << rang::fgB::gray << rang::style::italic << format("'{}'", m_FilePath) 
                << "\n";
            cout << rang::fgB::green << "\tline: "
                << rang::fgB::gray << rang::style::italic << m_Line
                << "\n";
            cout << rang::fgB::green << "\tfunc: "
                << rang::fgB::gray << rang::style::italic << format("<{}>", m_Function)
                << "\n";
            cout << rang::fgB::green << "\treason: "
                << rang::fgB::gray << rang::style::italic << format("'{}'", m_Description)
                << "\n";
            cout << rang::fg::green << "for full info go to: "
                << rang::fgB::gray << rang::style::italic << format("'{}'", m_ErrorLogFilePath)
                << std::endl;
            
            //TODO: set it to the log file

            return ToString();
;        }
    }
}