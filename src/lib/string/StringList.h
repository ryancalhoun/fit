#pragma once

#include <string>
#include <list>

class StringList
{
public:
	StringList();

	template <template <typename, typename> class V, typename A>
	StringList(const V<std::string,A>& list);

	template <typename I>
	StringList(const I& begin, const I& end);

	bool empty() const;

	StringList& append(const std::string& str);
	StringList& operator<<(const std::string& str);

	void pop();

	template <template <typename,typename> class V, typename A>
	StringList& concat(const V<std::string,A>& list);

	template <typename I>
	StringList& concat(const I& begin, const I& end);

	std::string join(char c) const;

protected:
	std::list<std::string> _list;
};

template <template <typename, typename> class V, typename A>
StringList::StringList(const V<std::string,A>& list)
{
	concat(list);
}

template <typename I>
StringList::StringList(const I& begin, const I& end)
{
	concat(begin, end);
}

template <template <typename,typename> class V, typename A>
StringList& StringList::concat(const V<std::string,A>& list)
{
	return concat(list.begin(), list.end());
}

template <typename I>
StringList& StringList::concat(const I& begin, const I& end)
{
	for(I it = begin; it != end; ++it)
		append(*it);
	return *this;
}

