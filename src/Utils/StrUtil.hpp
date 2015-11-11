#pragma once

#ifndef STRUTIL_H
#define STRUTIL_H

#include <string>
#include <vector>
#include <Windows.h>

namespace StrUtil
{
	inline std::wstring AnsiToUnicode(const char* buf);
	inline std::string AnsiToUtf8(const char* buf);
	inline std::string UnicodeToAnsi(const wchar_t* buf);
	inline std::wstring Utf8ToUnicode(const char* buf);
	inline std::string UnicodeToUtf8(const wchar_t* buf);
	inline std::string TrimLeft(const std::string& str);
	inline std::string TrimRight(const std::string& str);
	inline std::string Trim(const std::string& str);
	inline std::vector<std::string> Split(std::string& str, const char* c);
	inline std::string GetModulePath();
	inline HMODULE GetCurrentModule();
};

namespace StrUtil {

	std::vector<std::string> Split(std::string& str, const char* c)
	{
		char *cstr, *p;
		std::vector<std::string> res;
		cstr = new char[str.size() + 1];
		strcpy(cstr, str.c_str());
		p = strtok(cstr, c);
		while (p != NULL)
		{
			res.push_back(p);
			p = strtok(NULL, c);
		}
		return res;
	}

	std::wstring AnsiToUnicode(const char* buf)
	{
		int len = ::MultiByteToWideChar(CP_ACP, 0, buf, -1, NULL, 0);
		if (len == 0) return L"";
		std::vector<wchar_t> unicode(len);
		::MultiByteToWideChar(CP_ACP, 0, buf, -1, &unicode[0], len);
		return &unicode[0];
	}

	std::string AnsiToUtf8( const char* buf )
	{
		return UnicodeToUtf8(AnsiToUnicode(buf).c_str());
	}

	std::string UnicodeToAnsi(const wchar_t* buf)
	{
		int len = ::WideCharToMultiByte(CP_ACP, 0, buf, -1, NULL, 0, NULL, NULL);
		if (len == 0) return "";
		std::vector<char> utf8(len);
		::WideCharToMultiByte(CP_ACP, 0, buf, -1, &utf8[0], len, NULL, NULL);
		return &utf8[0];
	}

	std::wstring Utf8ToUnicode(const char* buf)
	{
		int len = ::MultiByteToWideChar(CP_UTF8, 0, buf, -1, NULL, 0);
		if (len == 0) return L"";
		std::vector<wchar_t> unicode(len);
		::MultiByteToWideChar(CP_UTF8, 0, buf, -1, &unicode[0], len);
		return &unicode[0];
	}

	std::string UnicodeToUtf8(const wchar_t* buf)
	{
		int len = ::WideCharToMultiByte(CP_UTF8, 0, buf, -1, NULL, 0, NULL, NULL);
		if (len == 0) return "";
		std::vector<char> utf8(len);
		::WideCharToMultiByte(CP_UTF8, 0, buf, -1, &utf8[0], len, NULL, NULL);
		return &utf8[0];
	}

	std::string TrimLeft(const std::string& str) {
		std::string t = str;
		for (std::string::iterator i = t.begin(); i != t.end(); i++) {
			if (!isspace(*i)) {
				t.erase(t.begin(), i);
				break;
			}
		}
		return t;
	}

	std::string TrimRight(const std::string& str) {
		if (str.begin() == str.end()) {
			return str;
		}
		std::string t = str;
		for (std::string::iterator i = t.end() - 1; i != t.begin(); i--) {
			if (!isspace(*i)) {
				t.erase(i + 1, t.end());
				break;
			}
		}
		return t;
	}

	std::string Trim(const std::string& str) {
		std::string t = str;

		std::string::iterator i;
		for (i = t.begin(); i != t.end(); i++) {
			if (!isspace(*i)) {
				t.erase(t.begin(), i);
				break;
			}
		}
		if (i == t.end()) {
			return t;
		}

		for (i = t.end() - 1; i != t.begin(); i--) {
			if (!isspace(*i)) {
				t.erase(i + 1, t.end());
				break;
			}
		}
		return t;
	}

	HMODULE GetCurrentModule()
	{ // NB: XP+ solution!
		HMODULE hModule = NULL;
		GetModuleHandleEx(
			GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
			(LPCTSTR)GetCurrentModule,
			&hModule);

		return hModule;
	}

	std::string GetModulePath()
	{
		char fullPath[MAX_PATH];
		char drive[_MAX_DRIVE];
		char dir[_MAX_DIR];
		HMODULE hModule = GetCurrentModule();
		if(0 == GetModuleFileNameA(hModule, fullPath, MAX_PATH))
			return "";

		_splitpath(fullPath, drive, dir, NULL, NULL);
		std::string str = std::string(drive) + dir;
		return str;
	}
}

#endif