#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //如果链表为空，不用重排
        if (head == NULL)
            return head;
        //even开头指向第二个节点，可能为空
        ListNode* even = head->next;
        //odd开头指向第一个节点
        ListNode* odd = head;
        //指向even开头
        ListNode* evenhead = even;
        while (even != NULL && even->next != NULL) {
            //odd连接even的后一个，即奇数位
            odd->next = even->next;
            //odd进入后一个奇数位
            odd = odd->next;
            //even连接后一个奇数的后一位，即偶数位
            even->next = odd->next;
            //even进入后一个偶数位
            even = even->next;
        }
        //even整体接在odd后面
        odd->next = evenhead;
        return head;
    }
};
