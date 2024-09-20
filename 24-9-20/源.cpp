#define _CRT_SECURE_NO_WARNINGS 1

* struct ListNode {
    *int val;
    *struct ListNode* next;
    *
};
*/

class Solution {
public:
    /**
     *
     * @param head ListNodeÀà
     * @return ListNodeÀà
     */
    typedef struct ListNode* Node;
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        Node virnode = new ListNode(-1);
        virnode->next = head;
        Node pre = head;
        Node cur = head->next;
        while (cur)
        {
            if (cur->val == pre->val)
            {
                cur = cur->next;
                pre->next = cur;
            }
            else
            {
                cur = cur->next;
                pre = pre->next;
            }
        }
        return virnode->next;
    }
};
