#pragma once
#include <assert.h>
#include <iostream>
using namespace std;


namespace Zq
{
	class string
	{
		typedef char* iterator;
		typedef const char* const_iterator;

	public:
		iterator begin();
		iterator end();
		const_iterator begin()const;
		const_iterator end()const;

		string(const char* str = "");
		string(const string& s);
		~string();
		string operator=(string tmp);

		char* c_str()const;
		void swap(string& s);
		void reverse(size_t n);
		void clear();

		size_t size()const;
		size_t capacity()const;

		char operator[](size_t n);
		char operator[](size_t n)const;
		
		void append(const char* str);
		void push_back(char ch);
		void operator+=(const char* str);
		void operator+=(char ch);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos);


		bool operator<(const string& s)const;
		bool operator<=(const string& s)const;
		bool operator>(const string& s)const;
		bool operator>=(const string& s)const;
		bool operator==(const string& s)const;
		bool operator!=(const string& s)const;


	private:
		char* _str = nullptr;
		int _size = 0;
		int _capacity = 0;
	};

	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);

}