#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    //�ж���û�л������������ĵط�
    ListNode* hasCycle(ListNode* head) {
        //���ж�����Ϊ�յ����
        if (head == NULL)
            return NULL;
        //����˫ָ��
        ListNode* fast = head;
        ListNode* slow = head;
        //���û����ָ����ȵ�����β
        while (fast != NULL && fast->next != NULL) {
            //��ָ���ƶ�����
            fast = fast->next->next;
            //��ָ���ƶ�һ��
            slow = slow->next;
            //�������л�
            if (fast == slow)
                //���������ĵط�
                return slow;
        }
        //��ĩβ��û�л�
        return NULL;
    }

    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* slow = hasCycle(pHead);
        //û�л�
        if (slow == NULL)
            return NULL;
        //��ָ��ص���ͷ
        ListNode* fast = pHead;
        //�ٴ��������ǻ����
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
