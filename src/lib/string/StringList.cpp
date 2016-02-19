#include "StringList.h"

StringList::StringList()
{}

StringList& StringList::append(const std::string& str)
{
	_list.push_back(str);
	return *this;
}

StringList& StringList::operator<<(const std::string& str)
{
	_list.push_back(str);
	return *this;
}

std::string StringList::join(char c) const
{
	std::string s;
	for(std::list<std::string>::const_iterator it = _list.begin(); it != _list.end(); ++it)
	{
		if(it != _list.begin())
			s += c;
		s += *it;
	}

	return s;
}


