#pragma once 

#include "src/FileManagment/BasicFile.h"
#include "src/FileManagment/DataStructures/DataFileStructure.h"

#include <string>

namespace Core
{
    class DataFile : public File
    {
    public:
        DataFile(const string path);
        ~DataFile();

        void Load();
        void Save();

        DataFileStructure& GetData();

        // String values
        void SetString(const string& value, const size_t itemIndex);
        const string GetString(const size_t itemIndex) const;
        
        // Real values
        void SetReal(const double value, const size_t itemIndex);
        const double GetReal(const size_t itemIndex) const;

        // Int values
        void SetInt(const int value, const size_t itemIndex);
        const int32_t GetInt(const size_t itemIndex) const;

        // Utils
        size_t GetValueCount() const;
        const std::vector<std::pair<string, DataFileStructure>>& GetObjects() const;

        // Operators
        DataFileStructure& operator[](const string& name);

    private:
        DataFileStructure m_data;
    };
}
