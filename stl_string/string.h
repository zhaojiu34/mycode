#pragma once
#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

namespace aa
{
	class string
	{
		typedef char* iterator;
		typedef const char* const_iterator;
	public:

		//迭代器
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end()const;

		//构造和析构
		string(const char* str = "");
		string(const string& s);
		//string& operator=(const string& s);
		//string& operator=(const string& tmp);
		string& operator=(string tmp);


		~string();

		//打印
		const char* c_str();
		//返回有效值
		size_t size()const;

		//开空间
		void reserve(int n);
		//清理屏幕
		void clear();
		void swap(string& s);

		//下表访问
		char operator[](size_t pos);
		char operator[](size_t pos)const;

		//插入删除
		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos, size_t len = npos);

		void append(const char* str);
		void push_back(char ch);
		void operator+=(char ch);
		void operator+=(const char* str);

		size_t find(char ch);
		size_t find(const char* str,size_t pos);

		string sub(size_t pos = 0, size_t len = npos);

		//比较大小
		bool operator>(const string& s)const;
		bool operator>=(const string& s)const;
		bool operator<(const string& s)const;
		bool operator<=(const string& s)const;
		bool operator==(const string& s)const;
		bool operator!=(const string& s)const;


	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;
	};

	ostream& operator<<(ostream& os, const string& s);
	istream& operator>>(istream& is, string& s);
}
