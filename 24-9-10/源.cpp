#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;


struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    
};


ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if (head->next == nullptr)
        return head;

    if (n - m == 0)
        return head;

    ListNode* cur = head;
    ListNode* left = head;
    ListNode* right = head;
    ListNode* prev = nullptr;
    ListNode* next = head->next;

    int num = 1;

    if (num == m)
    {
        left = head;
        prev = nullptr;
    }

    while (num <= n)
    {
        if (num + 1 == m)
        {
            left = cur->next;
            prev = cur;
        }

        if (num == n)
        {
            right = cur;
            next = cur->next;
        }

        cur = cur->next;
        num++;
    }

    ListNode* n1 = next;
    ListNode* n2 = left;
    ListNode* n3 = left->next;

    while (n2 != next)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3 != next)
            n3 = n3->next;
    }

    //区分m如果是头节点和不是头节点两种情况

    if (prev != nullptr)
        prev->next = right;
    else
        return n1;

    return head;

}



int main()
{
    ListNode n1(3);
    ListNode n2(5);

    n1.next = &n2;
    n2.next = nullptr;

    reverseBetween(&n1, 1, 2);

    return 0;

}