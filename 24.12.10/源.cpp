#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include<string>

using namespace std;


struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};

//链表的奇偶重排
ListNode* oddEvenList(ListNode* head)
{

    ListNode left(-1);
    ListNode right(-1);

    ListNode* lefthead = &left;
    ListNode* righthead = &right;

    ListNode* cur = head;
    ListNode* pre = head;
    ListNode* curl = lefthead;
    ListNode* curr = righthead;
    int n = 0;


    while (cur)
    {
        if (n % 2 == 0)
        {
            cur = cur->next;
            curr->next = pre;
            pre->next = nullptr;
            curr = curr->next;
        }
        else
        {
            cur = cur->next;
            curl->next = pre;
            pre->next = nullptr;
            curl = curl->next;
        }

        pre = cur;
        n++;
    }

    curr->next = lefthead->next;

    return righthead->next;
}


//删除有序链表中重复的元素 - I
class Solution {
public:
    
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr)
            return head;

        ListNode node(-1);
        ListNode* myhead = &node;

        ListNode* cur = head;
        ListNode* pre = head;
        ListNode* mycur = myhead;

        while (cur)
        {
            if (cur->val != mycur->val)
            {
                cur = cur->next;
                mycur->next = pre;
                pre->next = nullptr;
                mycur = mycur->next;
            }
            else
            {
                cur = cur->next;
            }

            pre = cur;
        }

        return myhead->next;
    }
};

int main()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);

    ListNode* head = &node1;

    ListNode* cur = head;

    cur->next = &node2;
    cur = cur->next;
    cur->next = &node3;
    cur = cur->next;
    cur->next = &node4;
    cur = cur->next;
    cur->next = &node5;
    cur = cur->next;
    cur->next = &node6;
    cur = cur->next;
    cur->next = nullptr;


    oddEvenList(head);

    int a = 1;
	return 0;
}