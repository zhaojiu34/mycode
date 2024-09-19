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
     * @param head ListNode��
     * @return ListNode��
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        ListNode* newhead = new ListNode(0);//����һ����ʼ����
        newhead->next = head;//��head������ӵ�newhead��
        ListNode* pre = newhead;
        ListNode* cur = head;
        int count = 0;//�����ظ�����
        while (cur != NULL && cur->next != NULL) {//�ж�����
            if (cur->val == cur->next->val) {//�������˳��ֵ���
                cur->next = cur->next->next;//ɾ����Ԫ��
                count++;//��count������һ�ٴν����ж�
            }
            else {
                if (count > 0) {
                    pre->next = cur->next;//����Ԫ��ֵȫ��ɾ��
                    count = 0;
                }
                else
                    pre = cur;
                cur = cur->next;//�ݹ�����
            }
        }
        if (count > 0)//���ڱ���{1��2��2}����Ϊɾ������������ѭ�������������жϣ��ڴ˶�������ж�
            pre->next = cur->next;
        return newhead->next;
    }
};