#define _CRT_SECURE_NO_WARNINGS 1
#include "String.h"


namespace Zq
{
	size_t string::npos = -1;

	//迭代器
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
	string::const_iterator string::end() const
	{
		return _str + _size;
	}

	//构造和析构，赋值
	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		_capacity = _size;
		strcpy(_str, str);
	}

	string::string(const string& s)
		:_size(s._size)
		,_capacity(s._capacity)
	{
		_str = new char[s._capacity + 1];
		strcpy(_str, s._str);
	}

	/*string& string::operator=(const string& s)
	{
		_size = s._size;
		_capacity = s._capacity;
		strcpy(_str, s._str);

		return *this;
	}*/

	string& string::operator=(const string& s)
	{
		if (this != &s)
		{
			char* tmp = new char[s._capacity + 1];
			_size = s._size;
			_capacity = s._capacity;

			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
		}

		return *this;
	}

	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}

	//打印
	const char* string::c_str()const
	{
		return _str;
	}
	size_t string::size()const//返回有效个数
	{
		return _size;
	}


	char& string::operator[](size_t pos)
	{
		assert(pos < _size);

		return _str[pos];
	}
	char& string::operator[](size_t pos) const
	{
		assert(pos < _size);

		return _str[pos];
	}

	void string::reserve(size_t n)//改变capacity
	{
		if (_capacity < n)
		{
			char* s = new char[n+1];
			strcpy(s, _str);

			_capacity = n;
			
			delete[]_str;
			_str = s;
		}

	}
	void string::push_back(char ch)
	{
		/*if (_size == _capacity)
		{
			reserve(_capacity * 2);
		}
		_str[_size] = ch;
		_size++;*/

		insert(_size, ch);
	}
	void string::append(const char* str)
	{
		/*if (_capacity < _size + strlen(str))
		{
			reserve(_size + strlen(str));
		}

		strcpy(_str + _size, str);
		_size += strlen(str);*/

		insert(_size, str);

	}

	string& string::operator+=(const char* str)
	{
		/*if (_capacity < _size + strlen(str))
		{
			reserve(_size + strlen(str));
		}

		strcpy(_str + _size, str);
		_size += strlen(str);*/
		append(str);

		return *this;
	}
	string& string::operator+=(char ch)
	{
		/*if (_size == _capacity)
		{
			reserve(_capacity * 2);
		}
		_str[_size] = ch;
		_size++;*/

		push_back(ch);

		return *this;
		
	}

	void string::insert(size_t pos, char ch)
	{
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity * 2);
		}

		int i =_size;
		while (i >= (int)pos)
		{
			_str[i + 1] = _str[i];
			i--;
		}
		_str[pos] = ch;
		_size++;

	}
	void string::insert(size_t pos, const char* str)
	{
		size_t len = strlen(str);

		if (_capacity < _size + len)
		{
			reserve(_size + len);
		}

		int i =_size;
		while (i >= (int)pos)
		{
			_str[i+len] = _str[i];
			i--;
		}

		strcpy(_str+pos,str);
		//memcpy(_str + pos, str, len);

		_size += len;
				
	}
	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);

		if (len >= _size -pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			strcpy(_str + pos, _str +pos+len);
			_size -= len;
		}
	}

	size_t string::find(char ch, size_t pos)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}

		return -1;
	}
	size_t string::find(const char* str, size_t pos)
	{
		char* p = strstr(_str + pos, str);

		return p - _str;
	}

	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	string string::substr(size_t pos, size_t len )//取一部分子串
	{
		if (len > _size - pos)
		{
			string sub(_str + pos);
			return sub;
		}
		else
		{
			string sub;
			sub.reserve(len);
			for (size_t i = 0; i < len; i++)
			{
				sub += _str[pos + i];
			}

			return sub;
		}

	}

	//比较函数
	bool string::operator<(const string& s)const
	{
		return strcmp(_str, s._str) < 0;
	}
	bool string::operator<=(const string& s)const
	{
		return *this == s && *this < s;
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

	void string::clear()//清除原字符串
	{
		_str[0] = '\0';
		_size = 0;
	}

	istream& operator>>(istream& is, string& str)
	{
		str.clear();
		
		char ch = is.get();
		while (ch != ' '&& ch != '\n')
		{
			str += ch;
			ch = is.get();
		}

		return is;
	}

	ostream& operator<<(ostream& out, const string& str)
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			out << str[i];
		}
		
		return out;
	}
}