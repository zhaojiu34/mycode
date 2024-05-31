#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

namespace Zq
{

	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}
	string::const_iterator string::begin()const
	{
		return _str;
	}
	string::const_iterator string::end()const
	{
		return _str + _size;
	}


	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		_capacity = _size;
	}

	string::string(const string& s)
	{
		string tmp(s._str);
		swap(tmp);

	}
	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}

	string string::operator=(string tmp)
	{
		swap(tmp);
		return *this;
	}

	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	void string::reverse(size_t n)
	{
		if (_capacity < n)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);

			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::clear()
	{
		_str[0] = '\0';
	}

	char* string::c_str()const
	{
		return _str;
	}

	size_t string::size()const
	{
		return _size;
	}
	size_t string::capacity()const
	{
		return _capacity;
	}

	char string::operator[](size_t n)
	{
		return _str[n];
	}
	char string::operator[](size_t n)const
	{
		return _str[n];
	}

	void string::append(const char* str)
	{
		insert(_size, str);
	}
	void string::push_back(char ch)
	{
		insert(_size, ch);
	}
	void string::operator+=(const char* str)
	{
		append(str);
	}
	void string::operator+=(char ch)
	{
		push_back(ch);
	}


	void string::insert(size_t pos, char ch)
	{
		if (_capacity == _size)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reverse(newcapacity);
		}
		
		size_t end = _size;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}

		_str[pos] = ch;
		_size++;
	}

	void string::insert(size_t pos, const char* str)
	{
		int len = strlen(str);
		if (_capacity < _size + len)
		{
			reverse(_size + len);
		}

		size_t end = _size;
		while (end > pos)
		{
			_str[end] = _str[end-len];
			end--;
		}
		
		memcpy(_str + pos, str, len);
		_size += len;

	}


	void string::erase(size_t pos)
	{
		assert(pos < _size);

		int end = pos+1;
		while (end < _size)
		{
			_str[end-1] = _str[end];
			end++;
		}

		_size--;
	}


	bool string::operator<(const string& s)const
	{
		return strcmp(_str, s._str) < 0;
	}
	bool string::operator<=(const string& s)const
	{
		return *this < s&&* this == s;
	}
	bool string::operator>(const string& s)const
	{
		return strcmp(_str, s._str) > 0;
	}
	bool string::operator>=(const string& s)const
	{
		return *this > s && *this == s;
	}
	bool string::operator==(const string& s)const
	{
		return strcmp(_str, s._str) == 0;
	}
	bool string::operator!=(const string& s)const
	{
		return !(*this == s);
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i] << endl;
		}

		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch = in.get();
		while (ch != ' ' && ch != '\0')
		{
			s += ch;

			ch = in.get();
		}

		return in;
	}


}