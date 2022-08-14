#pragma once

#include <string>

#define CRaper _declspec(dllexport)

extern "C"
{
	CRaper void LogTest(std::string message);
}