#define _CRT_SECURE_NO_WARNINGS 1


class ListNode 
{
    int val;
    ListNode* next = null;
    public ListNode(int val) {
        this.val = val;
    }
}


class Solution {
public:
    //��ת����
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL)
            return NULL;
        ListNode* cur = pHead;
        ListNode* pre = NULL;
        while (cur != NULL) {
            //�Ͽ�����Ҫ��¼����һ��
            ListNode* temp = cur->next;
            //��ǰ��nextָ��ǰһ��
            cur->next = pre;
            //ǰһ������Ϊ��ǰ
            pre = cur;
            //��ǰ����Ϊ�ոռ�¼�ĺ�һ��
            cur = temp;
        }
        return pre;
    }

    ListNode* addInList(ListNode* head1, ListNode* head2) {
        //����һ������Ϊ�գ�������һ��
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;
        //��ת��������
        head1 = ReverseList(head1);
        head2 = ReverseList(head2);
        //��ӱ�ͷ
        ListNode* res = new ListNode(-1);
        ListNode* head = res;
        //��λ����
        int carry = 0;
        //ֻҪĳ�������л��߽�λ����
        while (head1 != NULL || head2 != NULL || carry != 0) {
            //����Ϊ����ȡ��ֵ
            int val1 = head1 == NULL ? 0 : head1->val;
            int val2 = head2 == NULL ? 0 : head2->val;
            //���
            int temp = val1 + val2 + carry;
            //��ȡ��λ
            carry = temp / 10;
            temp %= 10;
            //���Ԫ��
            head->next = new ListNode(temp);
            head = head->next;
            //�ƶ���һ��
            if (head1 != NULL)
                head1 = head1->next;
            if (head2 != NULL)
                head2 = head2->next;
        }
        //�����ת����
        return ReverseList(res->next);
    }
};
