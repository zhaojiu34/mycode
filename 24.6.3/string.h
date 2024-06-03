#pragma once
#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

namespace Zq
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin();
		iterator end();
		iterator begin()const;
		iterator end()const;

		string(const char* str = "");

		string(const string& s);
		string& operator=(string s);

		~string();

		void swap(string& s);
		void clear();
		void reverse(size_t n);
		size_t size();
		char* c_str();

		//插入删除
		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos,size_t len = npos);

		void push_back(char ch);
		void append(const char* s);
		void operator+=(const char* s);
		void operator+=(char ch);

		//下标访问
		char operator[](size_t n);
		char operator[](size_t n)const;

		//查找find
		size_t find(char ch);
		size_t find(size_t pos, const char* str);

		//取子串
		string sub(size_t pos, size_t len = npos);

		//比较
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);

	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;

		static size_t npos;
	};

	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& is, string& s);
}