#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

namespace Zq
{
	template <class T>
	class vector
	{
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}

		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _end_of_storage - _start;
		}

		void reverse(size_t n)
		{
			if (capacity() < n)
			{
				T* tmp = new T[n];
				size_t oldsize = size();

				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
				}

				delete[] _start;
				_start = tmp;
				_finish = _start + oldsize;
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void pop_back()
		{
			_finish--;
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos < _finish);
			assert(pos >= _start);

			if (_finish == _end_of_storage)
			{
				int len = pos - _start;

				int newcapacity = capacity() == 0 ? 4 : capacity() * 2;

				reverse(newcapacity);

				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end != pos)
			{
				*(end + 1) = *(end);
				end--;
			}

			++_finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			assert(pos >= _start);

			iterator end = pos;

			while (end != end())
			{
				*(end) = *(end + 1);
				end++;
			}
			
			_finish--;

			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
 	};
}
