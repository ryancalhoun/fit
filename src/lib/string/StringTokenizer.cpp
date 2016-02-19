#include "StringTokenizer.h"

#include <cstring>
#include <algorithm>

StringTokenizer::StringTokenizer(const std::string& source, char delimiter)
	: _source(source)
	, _delimiter(1, delimiter)
	, _pos(0)
{
}

void StringTokenizer::tokenize(const std::string& source)
{
	_source = source;
	_pos = 0;
}

void StringTokenizer::onText(const std::string& text)
{
	_delimiter = text;
}

void StringTokenizer::onCharset(const std::string& set)
{
	_charset = set;
}

bool StringTokenizer::split(std::vector<std::string>& result, size_t minimum/*=0*/)
{
	std::string part;
	while(next(part))
		result.push_back(part);
	return ! more() && result.size() >= minimum;
}

bool StringTokenizer::next(std::string& part)
{
	if(! more())
		return false;
	size_t begin = 0, end = 0;
	if(! _charset.empty())
	{
		begin = _source.find_first_not_of(_charset, _pos);
		_pos = _source.find_first_of(_charset, begin);
		if(begin == std::string::npos)
			return false;

		end = _pos;
	}
	else
	{
		begin = _pos;
		end = _source.find(_delimiter, begin);

		_pos = end;
		if(_pos != std::string::npos)
			_pos += _delimiter.size();
	}
	end = std::min(end, _source.size());
	part = _source.substr(begin, end - begin);
	return true;
}

bool StringTokenizer::more() const
{
	return _pos <= _source.size();
}

