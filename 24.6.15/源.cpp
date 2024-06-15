#define _CRT_SECURE_NO_WARNINGS 1

#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <queue>


using namespace std;

//字符串排序
//int main()
//{
//    int n;
//    cin >> n;
//    string ar[n];
//    for (int i = 0; i < n; i++)
//        cin >> ar[i];
//    sort(ar, ar + n);
//    for (int i = 0; i < n; i++)
//        cout << ar[i] << endl;
//    return 0;
//}


//整理唱片
//int main()
//{
//    int n;
//    while (cin >> n) {
//        list<int> lst;
//        list<int>::iterator j;
//        int t, c, a, b;
//        for (int i = 0; i < n; i++) {
//            cin >> t;
//            lst.push_back(t);
//        }
//        cin >> t;
//        for (int i = 0; i < t; i++) {
//            cin >> c;
//            switch (c) {
//            case 1:
//                cin >> a >> b;
//                for (j = lst.begin(); *j != a && j != lst.end(); j++)
//                    ;
//                if (j != lst.end())
//                    lst.insert(++j, b);
//                break;
//            case 2:
//                cin >> a;
//                for (j = lst.begin(); j != lst.end();)
//                    if (*j <= a)
//                        lst.erase(j++);
//                    else
//                        j++;
//                break;
//            case 3:
//                cin >> a >> b;
//                for (j = lst.begin(); *j != b && j != lst.end(); j++)
//                    ;
//                if (j != lst.end()) {
//                    lst.remove(a);
//                    for (j = lst.begin(); *j != b && j != lst.end(); j++)
//                        ;
//                    if (j != lst.end())
//                        lst.insert(++j, a);
//                }
//                break;
//            }
//        }
//        for (j = lst.begin(); j != lst.end(); j++) {
//            if (j != lst.begin())
//                cout << " ";
//            cout << *j;
//        }
//        cout << endl;
//    }
//    return 0;
//}




//哈哈型自动机
//int main()
//{
//    int m, n;
//    while (cin >> m)
//    {
//        cin >> n;
//        queue<int> a[m];
//        int v, b;
//        string x;
//        while (cin >> x)
//        {
//            if (x[0] == 'I')
//            {
//                for (int i = 0; i < m; ++i)
//                {
//                    while (!a[i].empty()) a[i].pop();
//                }
//            }
//            else if (x[0] == 'P' && x[1] == 'U')
//            {
//                cin >> v >> b;
//                a[v - 1].push(b);
//            }
//            else if (x[0] == 'P' && x[1] == 'O')
//            {
//                cin >> v;
//                if (a[v - 1].empty())
//                {
//                    cout << "NULL" << endl;
//                }
//                else
//                {
//                    cout << a[v - 1].front() << endl;;
//                    a[v - 1].pop();
//                }
//            }
//        }
//    }
//}


//呵呵型自动机
//int main()
//{
//    //    freopen("in.txt","r",stdin);
//    int m, n;
//    while (cin >> n >> m)
//    {
//        queue<int> que[n];
//        for (int i = 0; i < m; i++)
//        {
//            string order;
//            cin >> order;
//            if (order == "INIT")
//            {
//                for (int j = 0; j < n; j++)
//                    while (!que[j].empty())
//                        que[j].pop();
//            }
//            if (order == "PUSH")
//            {
//                int id, val, t;
//                cin >> id >> val >> t;
//                while (t--)
//                    que[id - 1].push(val);
//            }
//            if (order == "POP")
//            {
//                int id, t;
//                cin >> id >> t;
//                if (que[id - 1].empty())
//                    cout << "NULL" << endl;
//                else
//                {
//                    cout << que[id - 1].front() << endl;
//                    while (t--)
//                        que[id - 1].pop();
//                }
//
//            }
//        }
//    }
//
//}


//管道二
//int main()
//{
//    int n;
//    string t;
//    cin >> n;
//    deque<string>d;
//    for (int i = 0; i < n; i++)
//    {
//        int m;
//        cin >> m;
//        if (m == 1)
//        {
//            cin >> t;
//            d.push_front(t);
//        }
//        else if (m == 2)
//        {
//            cin >> t;
//            d.push_back(t);
//        }
//        else if (m == 3)
//        {
//            if (d.empty()) cout << "-1" << endl;
//            else cout << d.back() << endl;
//        }
//        else if (m == 4)
//        {
//            if (d.empty()) cout << "-1" << endl;
//            else cout << d.front() << endl;
//        }
//        else if (m == 5)
//        {
//            if (d.empty()) cout << "-1" << endl;
//            else d.pop_back();
//        }
//        else if (m == 6)
//        {
//            if (d.empty()) cout << "-1" << endl;
//            else d.pop_front();
//        }
//        else if (m == 0)
//        {
//            d.clear();
//        }
//    }
//}

#include <deque>

//管道一
//int main()
//{
//    ios::sync_with_stdio(false);
//    deque<string> D;
//    int n;
//    int op;
//    string ch;
//    cin >> n;
//    while (n--) {
//        cin >> op;
//        if (op == 1) {
//            cin >> ch;
//            D.push_front(ch);
//        }
//        else if (op == 2) {
//            if (D.empty()) cout << "-1" << endl;
//            else {
//                cout << D.back() << endl;
//                D.pop_back();
//            }
//        }
//        else if (op == 3) {
//            D.clear();
//        }
//    }
//    return 0;
//}


#include <set>

//邮票一
//int main()
//{
//    int n;
//    while (cin >> n && n != 0) {
//        multiset<int> ms;
//        int s;
//        char c;
//        while (n--) {
//            cin >> c;
//            switch (c) {
//            case 'B':
//                cin >> s;
//                ms.insert(s);
//                break;
//            case 'G':
//                multiset<int>::iterator i = ms.begin();
//                cout << *i << endl;
//                ms.erase(i);
//                break;
//            }
//        }
//    }
//    return 0;
//}

//多重级的插入和删除
int main()
{
    int n;
    while (cin >> n && n)
    {
        multiset <int> m;
        multiset <int> ::iterator  p;
        for (int i = 0; i < n; i++)
        {
            char order;
            int elem;
            cin >> order >> elem;
            if (order == 'i')
                m.insert(elem);
            if (order == 'd')
            {
                p = m.find(elem);
                m.erase(p);
            }
        }
        p = m.begin();
        cout << *p;
        p++;
        for (; p != m.end(); p++) cout << " " << *p;
        cout << endl;
    }
}

