#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //�������Ϊ�գ���������
        if (head == NULL)
            return head;
        //even��ͷָ��ڶ����ڵ㣬����Ϊ��
        ListNode* even = head->next;
        //odd��ͷָ���һ���ڵ�
        ListNode* odd = head;
        //ָ��even��ͷ
        ListNode* evenhead = even;
        while (even != NULL && even->next != NULL) {
            //odd����even�ĺ�һ����������λ
            odd->next = even->next;
            //odd�����һ������λ
            odd = odd->next;
            //even���Ӻ�һ�������ĺ�һλ����ż��λ
            even->next = odd->next;
            //even�����һ��ż��λ
            even = even->next;
        }
        //even�������odd����
        odd->next = evenhead;
        return head;
    }
};
