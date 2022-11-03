#include "Url.h"

#include <string>

using std::string;

namespace Core
{
	Url::Url() {}
	
	Url::Url(std::string url)
	{
		m_Url = url;
	}
	
	Url::~Url() {}
	
	void Url::SetUrl(std::string url)
	{
		m_Url = url;
	}
	
	void Url::SetProtocol(std::string protocol)
	{
		m_Protocol = protocol;
	}
	
	void Url::SetDomain(std::string domain)
	{
		m_Domain = domain;
	}
	
	void Url::SetPath(std::string path)
	{
		m_Path = path;
	}
	
	void Url::SetQuery(std::string query)
	{
		m_Query = query;
	}
	
	void Url::SetFragment(std::string fragment)
	{
		m_Fragment = fragment;
	}
	
	std::string Url::GetUrl()
	{
		return m_Url;
	}
	
	std::string Url::GetProtocol()
	{
		return m_Protocol;
	}
	
	std::string Url::GetDomain()
	{
		return m_Domain;
	}
	
	std::string Url::GetPath()
	{
		return m_Path;
	}
	
	std::string Url::GetQuery()
	{
		return m_Query;
	}
	
	std::string Url::GetFragment()
	{
		return m_Fragment;
	}
}