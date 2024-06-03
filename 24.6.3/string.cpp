#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

namespace Zq
{

	size_t string::npos = -1;

	//������
	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}
	string::iterator string::begin()const
	{
		return _str;
	}
	string::iterator string::end()const
	{
		return _str + _size;
	}


	//Ĭ�Ϲ���
	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		strcpy(_str, str);

		_capacity = _size;
	}

	//��������
	string::string(const string& s)
	{
		string tmp(s._str);
		swap(tmp);

	}

	//��ֵ
	string& string::operator=(string s)
	{
		swap(s);

		return *this;
	}
	//����
	string::~string()
	{
		delete[] _str;

		_str = nullptr;
		_size = _capacity = 0;
	}

	//����
	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);

	}
	//����
	void string::clear()
	{
		_str[0] = '\0';
	}

	//���ռ�
	void string::reverse(size_t n)
	{
		if (_capacity < n)
		{
			char* tmp = new char[n + 1];

			//���_str��Ϊ�գ��Ͱ�_str�����ݿ�����tmp
			if (_str)
			{
				strcpy(tmp, _str);
				delete[] _str;

				_str = tmp;
			}

			_capacity = n;
		}
	}

	//��Ч���ݵĸ���
	size_t string::size()
	{
		return _size;
	}


	//C���Դ�ӡ
	char* string::c_str()
	{
		return _str;
	}

	//����ɾ��
	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reverse(newcapacity);
		}

		size_t end = _size+1;
		while (end > pos)
		{
			_str[end] = _str[end-1];
			end--;
		}

		_str[pos] = ch;
		_size++;

	}


	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);

		size_t len = strlen(str);
		if (len + _size > _capacity)
		{
			reverse(len + _size);
		}

		int end = _size;
		while (end >= (int)pos)
		{
			_str[end + len] = _str[end];
			end--;
		}

		memcpy(_str + pos, str, len);
		_size += len;

	}


	void string::erase(size_t pos,size_t len)
	{
		assert(pos < _size);


		if (len >= _size - pos)
		{
			_str[pos] = '\0';

			_size = pos;
		}
		else
		{
			size_t end = pos;

			while (end+len >= _size)
			{
				_str[end] = _str[end + len];

				end++;
			}

			_size -= len;
		}
		
	}

	void string::push_back(char ch)
	{
		insert(_size, ch);
	}
	void string::append(const char* s)
	{
		insert(_size, s);
	}
	void string::operator+=(const char* s)
	{
		append(s);
	}
	void string::operator+=(char ch)
	{
		push_back(ch);
	}

	

	//�±����
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

	//����find
	size_t string::find(char ch)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_str[i] == ch)
				return i;
		}

		return -1;
	}
	size_t string::find(size_t pos,const char* str)
	{
		char* p = strstr(_str + pos, str);

		return p - _str;
	}


	//ȡ�Ӵ�
	string string::sub(size_t pos, size_t len)
	{
		if (len > _size - pos)
		{
			string sub(_str + pos);
			return sub;
		}
		else
		{
			char* tmp = new char[len + 1];

			for (size_t i = 0; i < len; i++)
			{
				tmp[i] = _str[pos + i];
			}
			tmp[len] = '\0';

			string sub(tmp);

			return sub;
		}
	}


	//�Ƚ�
	bool string::operator<(const string& s)
	{
		return strcmp(_str, s._str)<0;
	}
	bool string::operator<=(const string& s)
	{
		return *this < s && *this == s;
	}
	bool string::operator>(const string& s)
	{
		return strcmp(_str, s._str) > 0;
	}
	bool string::operator>=(const string& s)
	{
		return *this > s && *this == s;
	}
	bool string::operator==(const string& s)
	{
		return strcmp(_str, s._str) == 0;
	}
	bool string::operator!=(const string& s)
	{
		return !(*this == s);
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (const auto& e : s)
		{
			out << e;
		}

		return out;
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
		s += '\0';

		return is;
	}

}