#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == nullptr)
        return pHead2;
    if (pHead2 == nullptr)
        return pHead1;

    ListNode* head = new ListNode(-1);
    ListNode* h = head;

    ListNode* n1 = pHead1;
    ListNode* n2 = pHead2;

    while (n1 && n2)
    {
        if (n1->val <= n2->val)
        {
            h->next = n1;
            n1 = n1->next;
            h = h->next;
        }
        else {
            h->next = n2;
            h = h->next;
            n2 = n2->next;
        }
    }

    if (n1 == nullptr)
        h->next = n2;
    if (n2 == nullptr)
        h->next = n1;

    return head->next;
}



int main()
{

    ListNode n1 = 1;
    ListNode n2 = 16;
    ListNode n3 = 17;
    ListNode n4 = 16;
    ListNode n5 = 16;
    ListNode n6 = 16;
    

    n1.next = &n2;
    n2.next = &n3;
    n3.next = nullptr;


    n4.next = &n5;
    n5.next = &n6;
    n6.next = nullptr;



    Merge(&n1, &n4);
    return 0;
}