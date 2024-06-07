#define _CRT_SECURE_NO_WARNINGS 1


#include <algorithm>
#include <iostream>
#include <string>
#include<queue>
#include<stack>
#include <deque>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar, ar + n);
    for (int i = 0; i < n; i++)
        cout << ar[i] << endl;
    return 0;
}

int main()
{
    int n;
    while (cin >> n) {
        list<int> lst;
        list<int>::iterator j;
        int t, c, a, b;
        for (int i = 0; i < n; i++) {
            cin >> t;
            lst.push_back(t);
        }
        cin >> t;
        for (int i = 0; i < t; i++) {
            cin >> c;
            switch (c) {
            case 1:
                cin >> a >> b;
                for (j = lst.begin(); *j != a && j != lst.end(); j++)
                    ;
                if (j != lst.end())
                    lst.insert(++j, b);
                break;
            case 2:
                cin >> a;
                for (j = lst.begin(); j != lst.end();)
                    if (*j <= a)
                        lst.erase(j++);
                    else
                        j++;
                break;
            case 3:
                cin >> a >> b;
                for (j = lst.begin(); *j != b && j != lst.end(); j++)
                    ;
                if (j != lst.end()) {
                    lst.remove(a);
                    for (j = lst.begin(); *j != b && j != lst.end(); j++)
                        ;
                    if (j != lst.end())
                        lst.insert(++j, a);
                }
                break;
            }
        }
        for (j = lst.begin(); j != lst.end(); j++) {
            if (j != lst.begin())
                cout << " ";
            cout << *j;
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    int m, n;
    while (cin >> m)
    {
        cin >> n;
        queue<int> a[m];
        int v, b;
        string x;
        while (cin >> x)
        {
            if (x[0] == 'I')
            {
                for (int i = 0; i < m; ++i)
                {
                    while (!a[i].empty()) a[i].pop();
                }
            }
            else if (x[0] == 'P' && x[1] == 'U')
            {
                cin >> v >> b;
                a[v - 1].push(b);
            }
            else if (x[0] == 'P' && x[1] == 'O')
            {
                cin >> v;
                if (a[v - 1].empty())
                {
                    cout << "NULL" << endl;
                }
                else
                {
                    cout << a[v - 1].front() << endl;;
                    a[v - 1].pop();
                }
            }
        }
    }
}

int main()
{
    //    freopen("in.txt","r",stdin);
    int m, n;
    while (cin >> n >> m)
    {
        queue<int> que[n];
        for (int i = 0; i < m; i++)
        {
            string order;
            cin >> order;
            if (order == "INIT")
            {
                for (int j = 0; j < n; j++)
                    while (!que[j].empty())
                        que[j].pop();
            }
            if (order == "PUSH")
            {
                int id, val, t;
                cin >> id >> val >> t;
                while (t--)
                    que[id - 1].push(val);
            }
            if (order == "POP")
            {
                int id, t;
                cin >> id >> t;
                if (que[id - 1].empty())
                    cout << "NULL" << endl;
                else
                {
                    cout << que[id - 1].front() << endl;
                    while (t--)
                        que[id - 1].pop();
                }

            }
        }
    }

}
