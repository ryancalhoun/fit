#pragma once

#include <string>
#include <vector>

class StringTokenizer
{
public:
	StringTokenizer(const std::string& source = "", char delimiter=' ');

	void tokenize(const std::string& source);

	void onText(const std::string& text);
	void onCharset(const std::string& set);

	bool split(std::vector<std::string>& result, size_t minimum = 0);

	bool next(std::string& part);
	bool more() const;

protected:
	std::string        _source;
	std::string        _delimiter;
	std::string        _charset;
	size_t             _pos;
};

