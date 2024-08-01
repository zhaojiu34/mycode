#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;



//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//    
//};
//
//class Solution {
//public:
//    int getDecimalValue(ListNode* head)
//    {
//        int n = 0;
//        ListNode* cur = head;
//
//        while (cur)
//        {
//            n++;
//            cur = cur->next;
//        }
//
//        int ret = 0;
//        cur = head;
//        while (cur)
//        {
//            ret += pow(2, n - 1) * (cur->val);
//            n--;
//            cur = cur->next;
//        }
//
//        return ret;
//    }
//};
//
//
//int main()
//{
//    ListNode n1(1);
//    ListNode n2(0);
//    ListNode n3(1);
//
//    n1.next = &n2;
//    n2.next = &n3;
//    n3.next = nullptr;
//
//    Solution().getDecimalValue(&n1);
//
//    return 0;
//}



