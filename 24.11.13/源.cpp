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
            if (p1->val < p2->val) pre->next = p1, p1 = p1->next; // p1�Ľڵ�ֵС�ͽ�p1����Ҫ���ص�����
            else pre->next = p2, p2 = p2->next; // p2 �ڵ�ֵС�ڵ���p1�ͽ�p2 ���뷵�ص�����
            pre = pre->next;
        }
        // ��ʱ������һ�������Ѿ���ȫ����
        while (p1) pre->next = p1, p1 = p1->next, pre = pre->next; // ����û����ȫ������ p1
        while (p2) pre->next = p2, p2 = p2->next, pre = pre->next; // ����û����ȫ������ p2
        return fake->next;
    }
};