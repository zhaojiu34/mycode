#define _CRT_SECURE_NO_WARNINGS 1


class Solution {
public:
    bool hasCycle(ListNode* head) {
        //���ж�����Ϊ�յ����
        if (head == NULL)
            return false;
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
                return true;
        }
        //��ĩβ��û�л�
        return false;
    }
};
