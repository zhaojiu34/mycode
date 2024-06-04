#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

namespace Zq
{
    template<class T>

    class vector
    {

    public:

        // Vector的迭代器是一个原生指针

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

        const_iterator end() const
        {
            return _finish;
        }



            // construct and destroy

            vector()
                :_start(nullptr)
                ,_finish(nullptr)
                ,_endOfStorage(nullptr)
            {}

            vector(int n, const T& value = T())
            {

                for (size_t i = 0; i < n; i++)
                {
                    push_back(value);
                }

            }

            template<class InputIterator>

            vector(InputIterator first, InputIterator last)
            {
                auto it = first;

                while (it != last)
                {
                    push_back(*it);
                    it++;
                }

            }

            vector(const vector<T>& v)
            {
                vector tmp(v.begin(), v.end());
                swap(tmp);

            }


            vector<T>& operator= (vector<T> v)
            {
                swap(v);
                return *this;
            }

            ~vector()
            {
                delete[] _start;
                _finish = _start = _endOfStorage = nullptr;
            }

            // capacity

            size_t size() const
            {
                return _finish - _start;
            }

            size_t capacity() const
            {
                return _endOfStorage - _start;
            }


            //扩容
            void reserve(size_t n)
            {
                if (capacity() < n)
                {
                    size_t oldsize = size();

                    T* tmp = new T[n];
                    
                    memcpy(tmp, _start, sizeof(T) * oldsize);

                    delete[] _start;
                    _start = tmp;

                    _finish = _start + oldsize;
                    _endOfStorage = _start + n;

                }
            }
            
            //开空间，并初始化
            void resize(size_t n, const T& value = T())
            {
                _start = new T[n];
                _finish = _start;
                _endOfStorage = _start + n;

                for (size_t i = 0; i < n; i++)
                {
                    push_back(value);
                }


            }



            ///////////////access///////////////////////////////

            T& operator[](size_t pos)
            {
                assert(pos < size());

                return *(_start + pos);
            }

            const T& operator[](size_t pos)const
            {
                assert(pos < size());

                return *(_start + pos);
            }



            ///////////////modify/////////////////////////////

            void push_back(const T& x)
            {
                insert(end(), x);
            }

            void pop_back()
            {
                erase(end()-1);
            }

            void swap(vector<T>& v)
            {
                std::swap(_start, v._start);
                std::swap(_finish, v._finish);
                std::swap(_endOfStorage, v._endOfStorage);

            }

            //注意迭代器失效
            iterator insert(iterator pos, const T& x)
            {
                assert(pos <= _finish);
                assert(pos >= _start);

                if (_finish == _endOfStorage)
                {
                    int newcapacity = capacity() == 0 ? 4 : capacity() * 2;

                    int len = pos - _start;
                    reserve(newcapacity);
                    pos = _start + len;

                }

                iterator end = _finish;
                while (end != pos)
                {
                    *end = *(end - 1);
                    end--;
                }

                *pos = x;
                _finish++;

                return pos;
            }

            iterator erase(iterator pos)
            {
                assert(pos >= _start);
                assert(pos < _finish);

                iterator it = pos;

                while ((it + 1) != end())
                {
                    *it = *(it + 1);
                    it++;
                }

                _finish--;

                return pos;

            }


    private:

        iterator _start = nullptr; // 指向数据块的开始

        iterator _finish = nullptr; // 指向有效数据的尾

        iterator _endOfStorage = nullptr; // 指向存储容量的尾

    };


}
