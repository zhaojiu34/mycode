#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

namespace Zq
{
	size_t string::npos = -1;

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
		strcpy(_str, str);

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

	char* string::c_str()const
	{
		return _str;
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
		assert(n < _size);

		return _str[n];
	}

	char string::operator[](size_t n)const
	{
		assert(n < _size);

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
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reverse(newcapacity);
		}

		size_t end = _size + 1;
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
		size_t len = strlen(str);
		if (_size + len >= _capacity)
		{
			reverse(_size + len);
		}

		size_t end = _size;

		while ((int)end >= (int)pos)
		{
			_str[end + len] = _str[end];
			end--;
		}
		
		memcpy(_str + pos, str, len);
		_size += len;

	}

	void string::erase(size_t pos, size_t len)
	{
		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			strcpy(_str + pos, _str + pos+len);

			_size -= len;
		}
	}

	size_t string::find(char ch)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_str[i] == ch)
				return i;
		}
		return -1;
	}

	size_t string::find(const char* str,size_t pos)
	{
		char* p = strstr(_str+pos, str);

		return p - _str;
	}

	bool string::operator<(const string& s)const
	{
		return strcmp(_str, s._str) < 0;
	}

	bool string::operator<=(const string& s)const
	{
		return *this < s && *this == s;
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

}