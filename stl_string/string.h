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

		//������
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end()const;

		//���������
		string(const char* str = "");
		string(const string& s);
		//string& operator=(const string& s);
		//string& operator=(const string& tmp);
		string& operator=(string tmp);


		~string();

		//��ӡ
		const char* c_str();
		//������Чֵ
		size_t size()const;

		//���ռ�
		void reserve(int n);
		//������Ļ
		void clear();
		void swap(string& s);

		//�±����
		char operator[](size_t pos);
		char operator[](size_t pos)const;

		//����ɾ��
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

		//�Ƚϴ�С
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
