#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>

using namespace std;



 struct ListNode {
     int val;
     struct ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
  };
 

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head)
    {
        ListNode* n1 = nullptr;
        ListNode* n2 = head;
        ListNode* n3 = head->next;

        while (n2)
        {
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            if (n3)
                n3 = n3->next;

        }

        return n1;
    }
};