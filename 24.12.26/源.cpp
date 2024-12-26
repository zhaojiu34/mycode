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

//随机表的复制
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
        //随机指针
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

    //将复制的那一份摘出来
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

//第一个入环的节点
//假设链表头距离入环节点L
//环的周长为C
//入环节点距离相遇节点为X
//fast走的距离：L+n*C+X fast在遇到slow时可能走了好几圈
//slow的距离：L+X
//fast 的距离是slow距离的2倍
//由此列等式可知，分别从链表和相遇点出发，最后一定可以在入环节点处相遇
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

//环形链表
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

//链表的回文结构
//反转链表
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

//找中间节点
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