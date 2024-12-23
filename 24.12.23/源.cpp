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
     * @param head ListNode�� the head node
     * @return ListNode��
     */
    ListNode* sortInList(ListNode* head) {
        vector<int> vec;
        ListNode* cur = head;
        // 1.����vector
        while (cur) {
            vec.push_back(cur->val);
            cur = cur->next;
        }
        // 2.vector����
        sort(vec.begin(), vec.end());
        // 3.��������
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