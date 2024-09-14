#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    //判断有没有环，返回相遇的地方
    ListNode* hasCycle(ListNode* head) {
        //先判断链表为空的情况
        if (head == NULL)
            return NULL;
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
                //返回相遇的地方
                return slow;
        }
        //到末尾则没有环
        return NULL;
    }

    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* slow = hasCycle(pHead);
        //没有环
        if (slow == NULL)
            return NULL;
        //快指针回到表头
        ListNode* fast = pHead;
        //再次相遇即是环入口
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
