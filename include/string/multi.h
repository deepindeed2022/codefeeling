#ifndef CF_INCLUDE_STRING_MULTI_H_
#define CF_INCLUDE_STRING_MULTI_H_
#include <cf_util.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cwctype>
#include <cctype>

std::string string_multi_op(std::string& s1, std::string& s2);
// split: receives a char delimiter; returns a vector of strings
// By default ignores repeated delimiters, unless argument rep == 1.
std::vector<std::string> split(std::string work, char delim, int rep=0);
std::string strToUpper(std::string& s);

inline std::string &lstrip(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

inline std::string &rstrip(std::string&s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

inline std::string &strip(std::string &s) {
    return lstrip(rstrip(s));
}

inline std::string &delete_punct(std::string& str) {
	str.erase(remove_if( str.begin(), str.end(), static_cast<int(*)(int)>(&ispunct)), str.end());
	return str;
}

inline std::wstring &delete_punct(std::wstring& str) {
	str.erase(remove_if( str.begin(), str.end(), static_cast<int(*)(wint_t)>(&iswpunct)), str.end());
	return str;
}

#endif