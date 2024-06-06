#pragma once

#include<iostream>
#include <assert.h>
#include <initializer_list>

using namespace std;


namespace Zq
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        //默认构造
        ListNode(const T& val = T())
            :_pPre(nullptr)
            ,_pNext(nullptr)
            ,_val(val)
        {}

        ListNode<T>* _pPre;
        ListNode<T>* _pNext ;
        T _val;
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct  ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;


        //构造迭代器
        ListIterator(PNode pNode = nullptr)
            :_pNode(pNode)
        {}

        ListIterator(const Self& l)
        {
            _pNode = l._pNode;
        }

        //获取数据
        T& operator*()
        {
            return _pNode->_val;
        }

        //返回数据地址
        T* operator->()
        {
            return &(_pNode->_val);
        }
        
        //++
        Self& operator++()
        {
            _pNode = _pNode->_pNext;

            return *this;
        }

        Self operator++(int)
        {
            ListIterator tmp(*this);

            _pNode = _pNode->_pNext;
            return tmp;
        }

        //--
        Self& operator--()
        {
            _pNode =  _pNode->_pPre;
            return *this;
        }

        Self& operator--(int)
        {
            ListIterator tmp(*this);
            _pNode = _pNode->_pPre;

            return tmp;
        }

        //判断
        bool operator!=(const Self& l)
        {
            return _pNode->_val != l._pNode->_val;
        }
        bool operator==(const Self& l)
        {
            return _pNode->_val == l._pNode->_val;
        }


        PNode _pNode = nullptr;
    };


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T&> const_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造
        list()
            :_pHead(nullptr)
        {
            CreateHead();
        }

        list(int n, const T& value = T())
        {
            CreateHead();
            for (size_t i = 0; i < n; i++)
            {
                push_back(value);
            }

        }

        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            CreateHead();
            while (first != last)
            {
                push_back(*first);
                first++;
            }

        }

        list(const list<T>& l)
        {
            CreateHead();

            list tmp(l.begin(),l.end());
            swap(tmp);

        }

        list(initializer_list<T> il)
        {
            CreateHead();
            for (const auto& e : il)
            {
                push_back(e);
            }
        }

        list<T>& operator=(list<T> l)
        {
            swap(l);

            return *this;
        }

        ~list()
        {
            clear();
            delete _pHead;
            _pHead = nullptr;
        }


        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return iterator(_pHead->_pNext);
        }

        iterator end()
        {
            return iterator(_pHead);
        }

        const_iterator begin() const
        {
            return const_iterator(_pHead->_pNext);
        }
        const_iterator end() const
        {
            return const_iterator(_pHead);
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            auto it = begin();

            size_t i = 0;
            while (it != end())
            {
                it++;
                i++;
            }

            return i;
        }

        bool empty()const
        {
            return _pHead->_pNext == _pHead->_pPre;
        }


        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            return _pHead->_pNext->_val;
        }

        const T& front()const
        {
            return _pHead->_pNext->_val;
        }

        T& back()
        {
            return _pHead->_pPre->_val;
        }
        const T& back()const
        {
            return _pHead->_pPre->_val;
        }


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) 
        { 
            insert(end(), val); 
        }

        void pop_back() 
        { 
            erase(--end()); 
        }

        void push_front(const T& val) 
        { 
            insert(begin(), val); 
        }

        void pop_front() 
        { 
            erase(begin()); 
        }


        // 在pos位置前插入值为val的节点
        //没有扩容，不存在迭代器失效
        iterator insert(iterator pos, const T& val)
        {
            PNode newnode = new Node;
            newnode->_val = val;

            PNode cur = pos._pNode;
            PNode pre = pos._pNode->_pPre;
            pre->_pNext = newnode;
            cur->_pPre = newnode;
            newnode->_pPre = pre;
            newnode->_pNext = cur;

            return iterator(newnode);

        }

        // 删除pos位置的节点，返回该节点的下一个位置
        //存在迭代器失效
        iterator erase(iterator pos)
        {
            assert(begin() != end());

            PNode del = pos._pNode;
            PNode pre = del->_pPre;
            PNode next = del->_pNext;

            pre->_pNext = next;
            next->_pPre = pre;

            delete del;
            return iterator(next);
        }


        void clear()
        {
            auto it = begin();
            while (it != end())
            {
                it = erase(it);
            }

        }

        void swap(list<T>& l)
        {
            std::swap(_pHead, l._pHead);
        }


    private:

        //设置哨兵位
        void CreateHead()
        {
            _pHead = new Node;
            _pHead->_pNext = _pHead;
            _pHead->_pPre = _pHead;
        }

        PNode _pHead = nullptr;
    };
};

