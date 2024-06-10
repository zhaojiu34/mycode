#pragma once
#include <iostream>
#include <assert.h>

using namespace std;



namespace Zq
{
    // List�Ľڵ���
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
            :_pPre(nullptr)
            ,_pNext(nullptr)
            ,_val(val)
        {}


        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };


    //List�ĵ�������
    //��Ϊ_pNode����Ϊ�����ϵ�������Ҫ�󣬰�_pNode��װ����������������Ϊ
    //����Ϊconst�Ͳ���constֻ�з���ֵ��ͬ�����඼��ͬ������д��һ��ģ��
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;

        ListIterator(PNode pNode = nullptr)
            :_pNode(pNode)
        {}


        ListIterator(const Self& l)
        {
            _pNode = l._pNode;
        }

        T& operator*()
        {
            return _pNode->_val;
        }

        T* operator->()
        {
            return &_pNode->_val;
        }


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

        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }

        Self& operator--(int)
        {
            ListIterator tmp(*this);
            _pNode = _pNode->_pPre;
            return tmp;
        }

        bool operator!=(const Self& l)
        {
            return _pNode->_val != l._pNode->_val;
        }

        bool operator==(const Self& l)
        {
            return _pNode->_val == l._pNode->_val;
        }

        PNode _pNode;
    };


    //list��
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
        // List�Ĺ���
        //�޲ι���
        list()
        {
            CreateHead();
        }

        //һ���Թ���n��value
        list(int n, const T& value = T())
        {
            CreateHead();
            for (size_t i = 0; i < n; i++)
            {
                push_back(value);
            }

        }

        //����������
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

        //��������
        list(const list<T>& l)
        {
            CreateHead();
            list tmp(l.begin(),l.end());

            swap(tmp);
          
        }


        list<T>& operator=(list<T> l)
        {
            CreateHead();
            
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
           return  iterator(_pHead);
        }

        const_iterator begin()const
        {
            return const_iterator(_pHead->_pNext);
        }

        const_iterator end()const
        {
            return const_iterator(_pHead);
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            size_t n = 0;
            auto it = begin();
            while (it != end())
            {
                n++;
                it++;
            }
            return n;
        }

        bool empty()const
        {
            return size() == 0;
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
        void push_back(const T& val) { insert(end(), val); }

        void pop_back() { erase(--end()); }

        void push_front(const T& val) { insert(begin(), val); }

        void pop_front() { erase(begin()); }

        // ��posλ��ǰ����ֵΪval�Ľڵ�
        iterator insert(iterator pos, const T& val)
        {
            PNode newnode = new Node;
            newnode->_val = val;

            PNode cur = pos._pNode;
            PNode pre = cur->_pPre;

            pre->_pNext = newnode;
            cur->_pPre = newnode;
            newnode->_pPre = pre;
            newnode->_pNext = cur;

            return iterator(newnode);
        }

        // ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
        iterator erase(iterator pos)
        {
            assert(!empty());

            PNode del = pos._pNode;
            PNode pre = del->_pPre;
            PNode next = del->_pNext;

            pre->_pNext = next;
            next->_pPre = pre;

            delete del;
            del = nullptr;

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

        //�����ڱ�λ
        void CreateHead()
        {
            _pHead = new Node;
            _pHead->_pNext = _pHead;
            _pHead->_pPre = _pHead;
        }

        PNode _pHead;
    };
};