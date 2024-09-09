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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param head ListNode��
     * @return ListNode��
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