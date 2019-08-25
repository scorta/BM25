#include "./header/text.hpp"

Text::Text(const std::string& s) : content{ s } {
	std::istringstream ss{ s };
	length = 0;
	for (std::string tok; ss >> tok;) {
		++tokens[tok];
		++length;
	}
}

size_t Text::get_length() const {
	return length;
}

Document::Document(const std::string& s) : Text{ s }, score { 0 } { }