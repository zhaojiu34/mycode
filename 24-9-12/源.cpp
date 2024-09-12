#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	ListNode* merge(ListNode* p, ListNode* q) {
		if (!p || !q)return !q ? p : q;//如一个链表为空，则直接返回另外一个 
		ListNode* head = new ListNode(0), * s = head;//新建链表，及其头指针 
		while (p && q) {//在两个链表的公共部分，将权值较小的结点放在新建链表后 
			if (p->val < q->val) {
				s->next = p;
				p = p->next;
			}
			else {
				s->next = q;
				q = q->next;
			}
			s = s->next;//指针后移 
		}
		if (p)s->next = p;//如果两个链表谁还有剩余，则接在新建链表后 
		else s->next = q;
		return head->next;//返回排序后的链表 
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* head = NULL;
		for (int i = 0; i < lists.size(); i++) {
			head = merge(head, lists[i]);//依次将两个链表合并 
		}
		return head;//返回结果链表 
	}
};
