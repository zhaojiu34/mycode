#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>


using namespace std;

//用栈实现队列
class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                int top = s1.top();
                s2.push(top);
                s1.pop();
            }
        }
        int top = s2.top();
        s2.pop();

        return top;
    }

    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                int top = s1.top();
                s2.push(top);
                s1.pop();
            }
        }
        int top = s2.top();


        return top;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    stack<int> s1;
    stack<int> s2;
};

//用队列实现栈
class MyStack {
public:

    MyStack() {
    }

    void push(int x)
    {
        if (q1.empty())
        {
            q2.push(x);
        }
        else
        {
            q1.push(x);
        }
    }

    int pop()
    {
        size_t size1 = q1.size();
        size_t size2 = q2.size();

        if (!q1.empty())
        {
            while (size1 > 1)
            {
                int front = q1.front();
                q1.pop();
                size1--;

                q2.push(front);
            }

            int front = q1.front();
            q1.pop();
            return front;
        }
        else
        {
            while (size2 > 1)
            {
                int front = q2.front();
                q2.pop();
                size2--;

                q1.push(front);
            }

            int front = q2.front();
            q2.pop();
            return front;
        }
    }


    int top()
    {
        size_t size1 = q1.size();
        size_t size2 = q2.size();

        if (!q1.empty())
        {
            while (size1 > 1)
            {
                int front = q1.front();
                q1.pop();
                size1--;

                q2.push(front);
            }

            int front = q1.front();
            q1.pop();
            q2.push(front);
            return front;
        }
        else
        {
            while (size2 > 1)
            {
                int front = q2.front();
                q2.pop();
                size2--;

                q1.push(front);
            }

            int front = q2.front();
            q2.pop();
            q1.push(front);
            return front;
        }
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};

//循环队列
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        v.resize(k);
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }

        v[rare++] = value;
        cont++;

        rare %= v.size();
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;

        front++;
        cont--;
        front %= v.size();
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return v[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return v[(rare - 1 + v.size()) % v.size()];
    }

    bool isEmpty() {
        return cont == 0;
    }

    bool isFull() {
        return cont == v.size();
    }
private:
    vector<int> v;
    int front = 0;
    int rare = 0;
    int cont = 0;
};


//一元多项式求导
int main()
{
    int a = 0, b = 0;
    int flag = 1;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        if (b == 0)
        {
            if (flag)
                printf("0 0");
        }
        else
        {
            if (flag)
            {
                printf("%d %d", a * b, b - 1);
                flag = 0;
            }
            else
            {
                printf(" %d %d", a * b, b - 1);
            }
        }
    }

    return 0;
}
int main()
{
    MyStack my;
    my.push(1);
    my.push(2);
    cout << my.top() << " ";
    cout << my.pop() << " ";
    cout << my.pop() << " ";
    cout << my.empty()<<endl; 

	return 0;
}