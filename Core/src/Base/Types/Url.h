#pragma once

#include <string>

namespace Core
{
	class Url
	{
	public:
		Url();
		Url(std::string url);
		~Url();

		void SetUrl(std::string url);
		void SetProtocol(std::string protocol);
		void SetDomain(std::string domain);
		void SetPath(std::string path);
		void SetQuery(std::string query);
		void SetFragment(std::string fragment);

		std::string GetUrl();
		std::string GetProtocol();
		std::string GetDomain();
		std::string GetPath();
		std::string GetQuery();
		std::string GetFragment();
		
	private:
		std::string m_Url;
		std::string m_Protocol;
		std::string m_Domain;
		std::string m_Path;
		std::string m_Query;
		std::string m_Fragment;
	};
}