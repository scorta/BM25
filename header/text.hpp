#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <unordered_map>
#include <sstream>

class Text {
public:
	std::string content;
	std::unordered_map<std::string, size_t> tokens;
	Text(const std::string& s);
	size_t get_length() const;

private:
	size_t length;
};

class Document : public Text {
public:
	Document(const std::string& s);
	double score;
};

#endif // !TEXT_H