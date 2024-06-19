#pragma once

#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

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
		void erase(size_t pos, size_t len = npos);

		size_t find(char ch);
		size_t find(const char* str,size_t pos = 0);


		bool operator<(const string& s)const;
		bool operator<=(const string& s)const;
		bool operator>(const string& s)const;
		bool operator>=(const string& s)const;
		bool operator==(const string& s)const;
		bool operator!=(const string& s)const;


	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;

		static size_t npos;
	};

	/*ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);*/

}
