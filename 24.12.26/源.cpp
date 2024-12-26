#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Node {
   int val;
    struct Node* next;
    struct Node* random;
};

typedef struct ListNode ListNode;
typedef struct Node  Node;

//�����ĸ���
struct Node* copyRandomList(struct Node* head)
{

    if (head == NULL)
        return NULL;

    Node* cur = head;

    while (cur)
    {
        Node* node = (Node*)malloc(sizeof(Node));
        node->val = cur->val;
        node->next = cur->next;
        cur->next = node;
        cur = cur->next->next;
    }

    cur = head;
    while (cur)
    {
        //���ָ��
        if (cur->random == NULL)
        {
            cur->next->random = NULL;
        }
        else
        {
            cur->next->random = cur->random->next;
        }

        cur = cur->next->next;
    }

    //�����Ƶ���һ��ժ����
    Node* newhead = head->next;
    Node* tail = newhead;

    cur = head->next->next;

    while (cur)
    {
        tail->next = cur->next;
        cur->next = tail->next->next;
        cur = cur->next;
        tail = tail->next;
    }

    tail->next = NULL;

    return newhead;
}

//��һ���뻷�Ľڵ�
//��������ͷ�����뻷�ڵ�L
//�����ܳ�ΪC
//�뻷�ڵ���������ڵ�ΪX
//fast�ߵľ��룺L+n*C+X fast������slowʱ�������˺ü�Ȧ
//slow�ľ��룺L+X
//fast �ľ�����slow�����2��
//�ɴ��е�ʽ��֪���ֱ���������������������һ���������뻷�ڵ㴦����
struct ListNode* detectCycle(struct ListNode* head)
{
    ListNode* fast = head, * slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            ListNode* meet = slow;
            while (meet && head)
            {
                if (meet == head)
                {
                    return meet;
                }

                meet = meet->next;
                head = head->next;
            }
        }
    }

    return NULL;
}

//��������
bool hasCycle(struct ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;

}

//����Ļ��Ľṹ
//��ת����
ListNode* Reverse(ListNode* head)
{
    ListNode* n1 = NULL, * n2 = head, * n3 = head->next;
    while (n2)
    {
        n2->next = n1;

        n1 = n2;
        n2 = n3;
        if (n3)
            n3 = n3->next;
    }

    return n1;
}

//���м�ڵ�
ListNode* MidList(ListNode* head)
{
    int len = 0;
    ListNode* cur = head;
    while (cur)
    {
        len++;
        cur = cur->next;
    }

    int cont = 0;
    cur = head;
    while (cur)
    {
        if (cont == len / 2)
        {
            break;
        }

        cont++;
        cur = cur->next;
    }

    return cur;
}

class PalindromeList {
public:
    bool chkPalindrome(ListNode* A)
    {
        ListNode* mid = MidList(A);
        ListNode* retmid = Reverse(mid);

        while (A && retmid)
        {
            if (A->val != retmid->val)
            {
                return false;
            }

            A = A->next;
            retmid = retmid->next;
        }

        return true;
    }
};


int main()
{



	return 0;
}