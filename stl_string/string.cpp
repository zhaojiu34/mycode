#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"

namespace aa
{
	const size_t string::npos = -1;

	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}
	string::const_iterator string::begin() const
	{
		return _str;
	}
	string::const_iterator string::end()const
	{
		return  _str + _size;
	}


	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		strcpy(_str, str);

		_capacity = _size;
	}

	////传统写法，自己开辟空间
	//string::string(const string& s)
	//	:_size(s._size)
	//	,_capacity(s._capacity)
	//{
	//	_str = new char[s._capacity + 1];
	//	strcpy(_str, s._str);

	//}

	//现代写法，别人干活
	string::string(const string& s)
	{
		string tmp(s._str);
		swap(tmp);
	}

	/*string& string::operator=(const string& s)
	{
		if (this != &s)
		{
			char* tmp = new char[s._capacity + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
			

			_size = s._size;
			_capacity = s._capacity;
		}

		return *this;
	}*/
	/*string& string::operator=(const string& tmp)
	{
		if (this != &tmp)
		{
			string s(tmp._str);
			swap(s);
		}

		return *this;
	}*/
	string& string::operator=(string tmp)
	{
		swap(tmp);

		return *this;
	}

	string::~string()
	{
		delete[] _str;
		_size = _capacity = 0;
	}

	//打印
	const char* string::c_str()
	{
		return _str;
	}
	//返回有效值
	size_t string::size()const
	{
		return _size;
	}

	void string::reserve(int n)
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
		_size = 0;
	}

	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);

	}

	void string::append(const char* str)
	{
		insert(_size, str);
	}
	void string::push_back(char ch)
	{
		insert(_size, ch);
	}
	void string::operator+=(char ch)
	{
		push_back(ch);
	}
	void string::operator+=(const char* str)
	{
		append(str);
	}

	void string::insert(size_t pos, char ch)
	{
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity);
		}

		int end = _size;
		while (end >= (int)pos)
		{
			_str[end+1] = _str[end];
			--end;
		}

		_str[pos] = ch;
		_size++;
	}

	void string::insert(size_t pos, const char* str)
	{
		int len = strlen(str);

		if (_capacity < _size + len)
		{
			reserve(_size + len);
		}

		int end = _size;
		while (end >= (int)pos)
		{
			_str[end + len] = _str[end];
			end--;
		}

		memcpy(_str + pos, str,len);
		_size += len;

	}
	void string::erase(size_t pos, size_t len)
	{
		if (len > _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			strcpy(_str + pos, _str + pos + len);

			_size -= len;
		}
	}


	char string::operator[](size_t pos)
	{
		assert(pos < _size);

		return _str[pos];
	}
	char string::operator[](size_t pos)const
	{
		assert(pos < _size);

		return _str[pos];
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
		char* p = strstr(_str, str);

		return p - _str;
	}
	
	string string::sub(size_t pos, size_t len)
	{
		if (len> _size)
		{
			string sub(_str + pos);
			return sub;
		}

		else
		{
			string sub;

			for (size_t i = 0; i < len; i++)
			{
				sub += _str[pos + i];
			}
			
			return sub;
		}
	}

	bool string::operator>(const string& s)const
	{
		return strcmp(_str, s._str) > 0;
	}
	bool string::operator>=(const string& s)const
	{
		return *this == s && *this > s;
	}
	bool string::operator<(const string& s)const
	{
		return strcmp(_str, s._str) < 0;
	}
	bool string::operator<=(const string& s)const
	{
		return *this < s && *this == s;
	}
	bool string::operator==(const string& s)const
	{
		return strcmp(_str, s._str) == 0;
	}
	bool string::operator!=(const string& s)const
	{
		return !(*this == s);
	}

	ostream& operator<<(ostream& os, const string& s)
	{
		for (size_t i = 0;i<s.size();i++)
		{
			os << s[i];
		}
		return os;
	}

	istream& operator>>(istream& is, string& s)
	{
		s.clear();

		char ch = is.get();
		while (ch != ' ' && ch != '\0')
		{
			s += ch;	
			ch = is.get();
		}
		
		return is;
	}
}