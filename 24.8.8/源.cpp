#define _CRT_SECURE_NO_WARNINGS 1

#include "AVLTree.h"


//class Solution {
//public:
//
//    struct Compare
//    {
//        bool operator()(const pair<string, int>& x, const pair<string, int>& y)
//        {
//            return x.second > y.second;
//        }
//    };
//
//
//    vector<string> topKFrequent(vector<string>& words, int k)
//    {
//        map<string, int> m;
//
//        for (const auto& e : words)
//        {
//            m[e]++;
//        }
//
//        vector<pair<string, int>> v(m.begin(), m.end());
//
//        stable_sort(v.begin(), v.end(), Compare());
//
//        vector<string> str;
//        for (size_t i = 0; i < k; i++)
//        {
//            str.push_back(v[i].first);
//        }
//
//        return str;
//
//    }
//};
//
//
//
//int main()
//{
//    string s;
//    map<string, int> contMap;
//
//    while (cin >> s)
//    {
//        string minS;
//        for (const auto& e : s)
//        {
//            if (e >= 'A' && e <= 'Z')
//            {
//                minS += e + 32;
//            }
//            else if (e >= 'a' && e <= 'z') {
//                minS += e;
//            }
//        }
//
//        contMap[minS]++;
//    }
//
//    vector<pair<string, int>> v(contMap.begin(), contMap.end());
//
//    for (const auto& e : v)
//    {
//        cout << e.first << ":" << e.second << endl;
//    }
//
//}
//// 64 Î»Êä³öÇëÓÃ printf("%lld")

void TestAVL()
{
	//int a[] = { 16,3,9,26,18,14,15 };
	int a[] = { 4,2,6,1,3,5,15,7,16,14};

	AVLTree<int> t;
	for (auto const& e : a)
	{
		t.Insert(e);
	}

	t.InOrder();

	cout << t.IsBalanceTree() << endl;

}


int main()
{
	TestAVL();

	return 0;
}