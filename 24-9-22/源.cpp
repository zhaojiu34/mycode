#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>

using namespace std;


struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
   
};


class Solution {
public:

    //合并k个已排序的链表
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 0)
            return nullptr;

        ListNode* head = new ListNode(-1);
        head->next = lists[0];

        for (size_t i = 1; i < lists.size(); i++)
        {
            ListNode* cur = head->next;
            ListNode* prev = head;
            ListNode* n1 = lists[i];

            while (n1 && cur)
            {
                if (n1->val <= cur->val)
                {
                    ListNode* next = n1->next;

                    prev->next = n1;
                    n1->next = cur;

                    n1 = next;
                    cur = prev;
                }

                prev = cur;
                cur = cur->next;
            }


            if (n1 != nullptr)
                prev->next = n1;
        }

        return head->next;
    }

    //判断链表是否有环
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr)
            return false;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }


    //链表中的入环节点
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;

        ListNode* fast = pHead;
        ListNode* slow = pHead;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                ListNode* meet = slow;

                while (meet != pHead)
                {
                    meet = meet->next;
                    pHead = pHead->next;
                }

                return meet;
            }
        }

        return nullptr;
    }


    //链表中倒数第K个节点
    ListNode* FindKthToTail(ListNode* pHead, int k)
    {
        if (pHead == nullptr)
            return nullptr;

        ListNode* cur = pHead;
        int len = 0;
        while (cur)
        {
            cur = cur->next;
            len++;
        }

        cur = pHead;

        if (len < k)
        {
            return nullptr;
        }
        else if (len == k)
        {
            return pHead;
        }
        else
        {
            int n = len - k;
            while (n--)
            {
                cur = cur->next;
            }

            return cur;
        }

        return nullptr;
    }


    //两个链表的公共节点
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
    {
        int len1 = 0;
        int len2 = 0;

        ListNode* n1 = pHead1;
        ListNode* n2 = pHead2;

        //先求两个链表的长度
        while (n1)
        {
            n1 = n1->next;
            len1++;
        }
        while (n2)
        {
            n2 = n2->next;
            len2++;
        }

        n1 = pHead1;
        n2 = pHead2;

        //将两个链表的长度差补齐
        int gap = len1 - len2;
        if (gap > 0)
        {
            while (gap--)
            {
                n1 = n1->next;
            }
        }
        else
        {
            int i = abs(gap);
            while (i--)
            {
                n2 = n2->next;
            }
        }

        //找交点
        while (n1 && n2)
        {
            if (n1 == n2)
            {
                return n1;
            }

            n1 = n1->next;
            n2 = n2->next;
        }

        return nullptr;

    }


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

    //两个链表相加
    ListNode* addInList(ListNode* head1, ListNode* head2)
    {
        if (head1 == nullptr)
            return head2;

        if (head2 == nullptr)
            return head1;

        //先反转，在运行相加后反转回来
        ListNode* newhead1 = ReverseList(head1);
        ListNode* newhead2 = ReverseList(head2);

        ListNode* n1 = newhead1;
        ListNode* n2 = newhead2;

        ListNode* prev = nullptr;
        //进制
        int n = 0;

        //链表相加
        while (n1 && n2)
        {
            int val = n1->val + n2->val + n;

            n1->val = val % 10;
            n2->val = val % 10;

            n = val / 10;

            prev = n1;
            n1 = n1->next;
            n2 = n2->next;
        }


        ListNode* head = newhead1;

        //n1所在的位数多
        if (n1 != nullptr)
        {
            //让多的每一位都与进制相加
            while (n1->next)
            {
                n1->val += n;

                n = n1->val / 10;
                n1->val %= 10;

                n1 = n1->next;
            }

            //判断最后一位是否大于10
            if (n1->val + n >= 10)
            {
                n = (n1->val + n) / 10;
                n1->val = (n1->val + n) % 10;
                ListNode* cur = new ListNode(n);
                n1->next = cur;
                cur->next = nullptr;
            }
        }
        //思路同n1
        else if (n2 != nullptr)
        {
            while (n2->next)
            {
                n2->val += n;

                n = n2->val / 10;
                n2->val %= 10;

                n2 = n2->next;
            }

            if (n2->val + n >= 10)
            {
                n = (n2->val + n) / 10;
                n2->val = (n2->val + n) % 10;
                ListNode* cur = new ListNode(n);
                n2->next = cur;
                cur->next = nullptr;
            }

            head = newhead2;
        }
        //如果两个链表位数相同，就只看最后一位是否大于10
        else
        {
            if (n != 0)
            {
                ListNode* cur = new ListNode(n);
                prev->next = cur;
                cur->next = nullptr;
            }

            head = newhead1;
        }
        
        //反转回去
        ListNode* newhead = ReverseList(head);

        return newhead;

    }

    //判断是否是回文结构
    bool isPail(ListNode* head)
    {
        int len = 0;
        ListNode* cur = head;

        while (cur)
        {
            len++;
            cur = cur->next;
        }

        int mid = len / 2;
        cur = head;

        while (mid--)
        {
            cur = cur->next;
        }

        ListNode* midlist = ReverseList(cur);

        while (midlist && head)
        {
            if (midlist->val != head->val)
                return false;

            head = head->next;
            midlist = midlist->next;
        }

        return true;

    }

};



int main()
{
    ListNode* n1 = new ListNode(9);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(7);
    ListNode* n4 = new ListNode(6);
    ListNode* n5 = new ListNode(3);
    ListNode* n6 = new ListNode(1);
    ListNode* n7 = new ListNode(1);
    ListNode* n8 = new ListNode(3);
    ListNode* n9 = new ListNode(-10);
    ListNode* n10 = new ListNode(-7);
    ListNode* n11 = new ListNode(-6);
    ListNode* n12 = new ListNode(-6);
    ListNode* n13 = new ListNode(-6);
    ListNode* n14 = new ListNode(0);
    ListNode* n15 = new ListNode(1);
    ListNode* n16 = new ListNode(3);
    ListNode* n17 = new ListNode(3);
    
    

    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;

    n4->next = n5;
    n5->next = nullptr;

   /* n6->next = n7;
    n7->next = n8;
    n8->next = nullptr;


    n9->next = n10;
    n10->next = n11;
    n11->next = n12;
    n12->next = n13;
    n13->next = n14;
    n14->next = n15;
    n15->next = n16;
    n16->next = n17;
    n17->next = nullptr;*/

    Solution().addInList(n1, n4);

	return 0;
}