#include "DataFile.h"

using std::string;

namespace Core
{
    DataFile::DataFile(const string path) : File(path)
    {
        m_data = DataFileStructure();
    }

    DataFile::~DataFile()
    {
    }

    void DataFile::Load()
    {
        m_data.Read(GetPath());
    }

    void DataFile::Save()
    {
        m_data.Write(GetPath());
    }

    DataFileStructure& DataFile::GetData()
    {
        return m_data;
    }

    void DataFile::SetString(const string& value, const size_t itemIndex)
    {
        m_data.SetString(value, itemIndex);
    }

    const string DataFile::GetString(const size_t itemIndex) const
    {
        return m_data.GetString(itemIndex);
    }

    void DataFile::SetReal(const double value, const size_t itemIndex)
    {
        m_data.SetReal(value, itemIndex);
    }

    const double DataFile::GetReal(const size_t itemIndex) const
    {
        return m_data.GetReal(itemIndex);
    }

    void DataFile::SetInt(const int value, const size_t itemIndex)
    {
        m_data.SetInt(value, itemIndex);
    }

    const int32_t DataFile::GetInt(const size_t itemIndex) const
    {
        return m_data.GetInt(itemIndex);
    }

    size_t DataFile::GetValueCount() const
    {
        return m_data.GetValueCount();
    }

    const std::vector<std::pair<string, DataFileStructure>>& DataFile::GetObjects() const
    {
        return m_data.GetObjects();
    }

    DataFileStructure& DataFile::operator[](const string& name)
    {
        return m_data[name];
    }
}
