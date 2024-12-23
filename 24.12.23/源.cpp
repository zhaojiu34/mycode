#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    
};

class Solution {
public:
    /**
     *
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        vector<int> vec;
        ListNode* cur = head;
        // 1.构建vector
        while (cur) {
            vec.push_back(cur->val);
            cur = cur->next;
        }
        // 2.vector排序
        sort(vec.begin(), vec.end());
        // 3.构建链表
        ListNode* dummy = new ListNode(0);
        ListNode* res = new ListNode(0);
        dummy->next = res;
        for (int i : vec) {
            res->next = new ListNode(i);
            res = res->next;
        }
        res->next = nullptr;
        return dummy->next->next;
    }
};