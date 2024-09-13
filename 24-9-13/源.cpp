#define _CRT_SECURE_NO_WARNINGS 1


class Solution {
public:
    bool hasCycle(ListNode* head) {
        //先判断链表为空的情况
        if (head == NULL)
            return false;
        //快慢双指针
        ListNode* fast = head;
        ListNode* slow = head;
        //如果没环快指针会先到链表尾
        while (fast != NULL && fast->next != NULL) {
            //快指针移动两步
            fast = fast->next->next;
            //慢指针移动一步
            slow = slow->next;
            //相遇则有环 
            if (fast == slow)
                return true;
        }
        //到末尾则没有环
        return false;
    }
};
