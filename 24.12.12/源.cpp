#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>
#include<set>

using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};

// 删除有序链表中重复的元素-II
ListNode* deleteDuplicates(ListNode* head)
{
    if (head == nullptr)
        return head;

    vector<int> v;
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
            v.push_back(cur->val);
            cur = cur->next;
        }

        pre = cur;
    }

    set<int> s(v.begin(), v.end());
    vector<int> vv(s.begin(), s.end());

    mycur = myhead->next;
    ListNode* mypre = myhead;
    int i = 0;
    while (mycur)
    {
        if (i <= (int)vv.size()-1 && mycur->val == vv[i])
        {
            i++;
            ListNode* node = mycur->next;
            mypre->next = node;
            mycur = node;
        }

        else
        {
            mypre = mycur;
            mycur = mycur->next;
        }

    }

    return myhead->next;
}


int main()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(2);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);

    ListNode* head = &node1;

    ListNode* cur = head;

    cur->next = &node2;
    cur = cur->next;
    cur->next = &node3;
    cur = cur->next;
    /*cur->next = &node4;
    cur = cur->next;
    cur->next = &node5;
    cur = cur->next;
    cur->next = &node6;
    cur = cur->next;*/
    cur->next = nullptr;

   // head->next = nullptr;

    deleteDuplicates(head);

    int a = 1;
    return 0;
}





////二分查找：双指针法
//class Solution {
//public:
//
//    int search(vector<int>& nums, int target)
//    {
//        int left = 0, right = nums.size() - 1;
//        int mid = (left + right) / 2;
//
//        while (left <= right)
//        {
//            if (nums[mid] == target)
//                return mid;
//            else if (nums[mid] < target)
//            {
//                left = mid + 1;
//                mid = (left + right) / 2;
//            }
//            else {
//                right = mid - 1;
//                mid = (left + right) / 2;
//            }
//        }
//        return -1;
//    }
//};
//int main()
//{
//    vector<int> v = { -2,-1,3 };
//    search(v, 3);
//
//	return 0;
//}