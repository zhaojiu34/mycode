#define _CRT_SECURE_NO_WARNINGS 1

/**
 * struct ListNode {
 *    int val;
 *    struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        ListNode* newhead = new ListNode(0);//设置一个初始链表
        newhead->next = head;//将head链表添加到newhead中
        ListNode* pre = newhead;
        ListNode* cur = head;
        int count = 0;//设置重复次数
        while (cur != NULL && cur->next != NULL) {//判断条件
            if (cur->val == cur->next->val) {//如果按照顺序，值相等
                cur->next = cur->next->next;//删除该元素
                count++;//将count次数加一再次进行判断
            }
            else {
                if (count > 0) {
                    pre->next = cur->next;//将该元素值全部删除
                    count = 0;
                }
                else
                    pre = cur;
                cur = cur->next;//递归条件
            }
        }
        if (count > 0)//存在比如{1，2，2}，因为删除，所以上述循环条件不进行判断，在此额外进行判断
            pre->next = cur->next;
        return newhead->next;
    }
};