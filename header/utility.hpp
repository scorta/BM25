#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <regex>

class utility {
public:
	static std::string remove_vn_tone(const std::string& s);
	static std::string remove_meaningless_char(const std::string& s);
};

#endif // !UTILITY_H