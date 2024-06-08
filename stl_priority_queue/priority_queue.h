#pragma once
#include <vector>
#include <iostream>
#include <assert.h>
#include<functional>


using namespace std;

template<class T>
class myless
{
public:
    bool operator()(const T& x, const T& y)
    {
        return x < y;
    }

};

template<class T>
class mygreater
{
public:
    bool operator()(const T& x, const T& y)
    {
        return x > y;
    }

};

namespace Zq
{
    //优先级队列相当于堆，默认是大堆，用 < 排序

    template <class T, class Container = vector<T>, class Compare = myless<T> >
    class priority_queue
    {
    public:

        //建堆
        priority_queue()
        {}

        template <class InputIterator>

        priority_queue(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                _c.push_back(*first);
                first++;
            }

            //采用
            for (int i = ((int)size() - 1 - 1) / 2; i >= 0; i--)
            {
                adjust_down(i);
            }

        }

        bool empty() const
        {
            return _c.empty();
        }

        size_t size() const
        {
            return _c.size();
        }

        const T& top() const
        {
            return _c[0];
        }

        void adjust_up(size_t child)
        {
            size_t parent = (child-1)/2;

            while (child > 0)
            {
                if (comp(_c[parent],_c[child]))
                {
                    swap(_c[parent], _c[child]);
                    child = parent;
                    parent = (child - 1) / 2;
                }

                else
                {
                    break;
                }

            }

        }

        void adjust_down(size_t parent)
        {
            size_t child = parent * 2 + 1;

            while (child < size())
            {
                if (child + 1 < size() && comp(_c[child], _c[child + 1]))
                {
                    child += 1;
                }


                if (comp(_c[parent], _c[child]))
                {
                    swap(_c[parent], _c[child]);
                    parent = child;
                    child = parent*2+1;
                }

                else
                {
                    break;
                }

            }

        }


        void push(const T& x)
        {
            _c.push_back(x);

            adjust_up(size() - 1);

        }

        void pop()
        {
            swap(_c[0], _c[size() - 1]);
            _c.pop_back();

            adjust_down(0);
        }

    private:

        Container _c;

        Compare comp;

    };

};
