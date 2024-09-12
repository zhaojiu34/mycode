#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	ListNode* merge(ListNode* p, ListNode* q) {
		if (!p || !q)return !q ? p : q;//��һ������Ϊ�գ���ֱ�ӷ�������һ�� 
		ListNode* head = new ListNode(0), * s = head;//�½���������ͷָ�� 
		while (p && q) {//����������Ĺ������֣���Ȩֵ��С�Ľ������½������ 
			if (p->val < q->val) {
				s->next = p;
				p = p->next;
			}
			else {
				s->next = q;
				q = q->next;
			}
			s = s->next;//ָ����� 
		}
		if (p)s->next = p;//�����������˭����ʣ�࣬������½������ 
		else s->next = q;
		return head->next;//�������������� 
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* head = NULL;
		for (int i = 0; i < lists.size(); i++) {
			head = merge(head, lists[i]);//���ν���������ϲ� 
		}
		return head;//���ؽ������ 
	}
};
