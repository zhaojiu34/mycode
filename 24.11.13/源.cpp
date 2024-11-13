#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
// c++
class Solution {
public:
    ListNode* Merge(ListNode* p1, ListNode* p2) {
        ListNode* fake = new ListNode(0), * pre = fake;
        while (p1 && p2) {
            if (p1->val < p2->val) pre->next = p1, p1 = p1->next; // p1的节点值小就将p1接入要返回的链表
            else pre->next = p2, p2 = p2->next; // p2 节点值小于等于p1就将p2 接入返回的链表
            pre = pre->next;
        }
        // 此时至少有一个链表已经完全遍历
        while (p1) pre->next = p1, p1 = p1->next, pre = pre->next; // 处理没有完全遍历的 p1
        while (p2) pre->next = p2, p2 = p2->next, pre = pre->next; // 处理没有完全遍历的 p2
        return fake->next;
    }
};