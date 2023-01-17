#pragma once

#include "src/FileManagment/BasicFile.h"

#include <string>
#include <exception>

namespace Core
{
    namespace Error
    {
        class Base : public std::exception
        {
        public:
            // (Con/De)structors
            Base(
                std::string Error,
                std::string Description,
                std::string FullDescription = "",
                std::string ErrorLogFilePath = "Log.log"
            );
            ~Base();

            std::string ToString();
            std::string FullString();

            std::string what();

        private:
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

        //FIXME: set the right error messages and fix the errors
        class SyntaxError : public Base
        {
            // Constructor
            SyntaxError() : Base("SyntaxError", "Wrong") {}
        };
        class FileError : public Base
        {
        public:
            // Constructor
            FileError() : Base("FileError", "Wrong") {}
        };

        class FileNotFound : public FileError
        {
            // Constructor
            FileNotFound() : FileError() {}
        };

        class FileAlreadyExists : public FileError
        {
            // Constructor
            FileAlreadyExists() : FileError() {}
        };

        class FileNotCreated : public FileError
        {
            // Constructor
            FileNotCreated() : FileError() {}
        };

        class FileNotDeleted : public FileError
        {
            // Constructor
            FileNotDeleted() : FileError() {}
        };

        class FileNotOpened : public FileError
        {
            // Constructor
            FileNotOpened() : FileError() {}
        };

        class FileNotClosed : public FileError
        {
            // Constructor
            FileNotClosed() : FileError() {}
        };

        class FileNotRead : public FileError
        {
            // Constructor
            FileNotRead() : FileError() {}
        };

        class FileNotWritten : public FileError
        {
            // Constructor
            FileNotWritten() : FileError() {}
        };

        class FileNotRenamed : public FileError
        {
            // Constructor
            FileNotRenamed() : FileError() {}
        };

        class FileNotCopied : public FileError
        {
            // Constructor
            FileNotCopied() : FileError() {}
        };
    }
} 
