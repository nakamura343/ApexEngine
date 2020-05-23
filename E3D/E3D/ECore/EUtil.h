#pragma once

#include "ECommon.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdarg.h>
#include <windows.h>
#include <ctime>

namespace E3D
{
	//全局LOG文件流
	extern std::ofstream *GLogStream;

	//初始化Log系统
	bool InitLog(const EString& fileName);

	void Log(const EChar* string, ...);

	void CloseLog();

	inline EInt RandomInt(EInt from = 0, EInt to = 10)
	{
		EInt ran = rand() % (to - from + 1) + from;
		return ran;
	}

	//整数转化成字符串
	inline EString IntToString(EFloat num)
	{
		std::stringstream ss;
		ss << num;
		EString es;
		ss >> es;
		return es;
	}

	//字符串转化成整数
	inline EInt StringToInt(const EString &str)
	{
		return atoi(str.c_str());
	}

	//字符串转化成浮点数
	inline EFloat StringToFloat(const EString &str)
	{
		return (EFloat)atof(str.c_str());
	}

	//转化成宽字符串
	inline EWString ToEWString(const EString &str)
	{
		int wcsLen = ::MultiByteToWideChar(CP_ACP, NULL, str.c_str(), str.size(), NULL, 0);
		WCHAR *tString = new WCHAR[wcsLen + 1];

		::MultiByteToWideChar(CP_ACP, NULL, str.c_str(), str.size(), tString, wcsLen);

		tString[wcsLen] = '\0';
		return EWString(tString);
	}

	inline EBool EqualFloat(EFloat l, EFloat r)
	{
		return abs(l - r) <= EPSILON_E6;
	}

	inline EString GetNameFromPath(const EString &path)
	{
		std::size_t beg = path.find_last_of("\\/");
		std::size_t end = path.find_first_of(".");

		if (beg == EString::npos)
			beg = -1;

		return path.substr(beg + 1, end - beg - 1);
	}

	// 将给定的字符串两端的空白字符删除
	inline EString Trim(const EString& msg)
	{
		const static EString SPACE_CAHR = "\t\f\v\n\r";
		std::size_t beg = msg.find_first_not_of(SPACE_CAHR);

		// 防止空字符串出现
		if (beg > msg.length())
			return EString();

		EString result = msg.substr(beg);
		std::size_t end = result.find_last_not_of(SPACE_CAHR);
		if (end != EString::npos)
			end++;

		return result.substr(0, end);
	}



}

