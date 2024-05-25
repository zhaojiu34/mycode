#pragma once

#include <iostream>
#include <assert.h>
#include <algorithm>

#include<stdlib.h>
using namespace std;

namespace Zq
{
	class string
	{
		
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		//迭代器
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		//构造和析构，赋值
		string(const char* str = "");
		string(const string& s);
		string& operator=(const string& s);
		~string();

		//打印
		const char* c_str()const;
		size_t size()const;//返回有效个数
		
		char& operator[](size_t pos);
		char& operator[](size_t pos) const;

		void reserve(size_t n);//改变capacity
		
		void push_back(char ch);
		void append(const char* str);

		string& operator+=(const char* str);
		string& operator+=(char ch);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos = 0, size_t len = npos);

		size_t find(char ch, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);

		void swap(string& s);
		string substr(size_t pos = 0, size_t len = npos);//取一部分子串

		//比较函数
		bool operator<(const string& s)const;
		bool operator<=(const string& s)const;
		bool operator>(const string& s)const;
		bool operator>=(const string& s)const;
		bool operator==(const string& s)const;
		bool operator!=(const string& s)const;

		void clear();//清除原字符串

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};

	istream& operator>>(istream& is, string& str);
	ostream& operator<<(ostream& out, const string& str);
}
