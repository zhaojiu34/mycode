#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��ʧ������
int missingNumber(int* nums, int numsSize)
{
    int sum = 0, max = 0;
    int min = INT_MAX;
    for (size_t i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        if (max < nums[i])
            max = nums[i];
        if (min > nums[i])
            min = nums[i];
    }

    int s = 0;
    for (size_t i = 0; i <= max; i++)
    {
        s += i;
    }

    if (s == sum)
    {
        if (min == 0)
            return max + 1;
        else
            return 0;
    }
    else
        return s - sum;
}

//��ת����
void reverse(int* num, int len)
{
    int left = 0, right = len - 1;
    while (left < right)
    {
        int tmp = num[left];
        num[left] = num[right];
        num[right] = tmp;

        left++;
        right--;
    }
}


void rotate(int* nums, int numsSize, int k)
{
    k %= numsSize;

    //��������ת
    reverse(nums, numsSize);
    //��[0,k-1]��ת   
    reverse(nums, k);
    //[k,len-1]��ת 
    reverse(nums + k, numsSize - k);
}

struct ListNode
{
    int val;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

//�ཻ����
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    int lenA = 0, lenB = 0;
    ListNode* curA = headA, * curB = headB;

    while (curA)
    {
        lenA++;
        curA = curA->next;
    }
    while (curB)
    {
        lenB++;
        curB = curB->next;
    }

    int len = abs(lenA - lenB);
    if (lenA < lenB)
    {
        ListNode* tmp = headA;
        headA = headB;
        headB = tmp;
    }

    curA = headA, curB = headB;
    while (len--)
    {
        curA = curA->next;
    }

    while (curA && curB)
    {
        if (curA == curB)
        {
            return curA;
        }

        curA = curA->next;
        curB = curB->next;
    }

    return NULL;
}

//���ص�����k���ڵ�
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    int lenA = 0,lenB= 0;
    ListNode *curA = headA,*curB = headB;

    while(curA)
    {
        lenA++;
        curA = curA->next;
    }    
    while(curB)
    {
        lenB++;
        curB = curB -> next;
    }

    int len = abs(lenA - lenB);
    if(lenA < lenB)
    {
        ListNode* tmp = headA;
        headA = headB;
        headB = tmp;
    }

    curA = headA,curB = headB;
    while(len--)
    {
        curA = curA->next;
    }

    while(curA && curB)
    {
        if(curA == curB)
        {
            return curA;
        }

        curA = curA->next;
        curB = curB -> next;
    }

    return NULL;
}

int kthToLast1(struct ListNode* head, int k)
{
    ListNode* slow = head, * fast = head;

    //��fast��slow���k�����ú�fast����βʱ��slow�͵��˵�����k��
    while (k--)
    {
        if (fast)
            fast = fast->next;
        else
            fast = NULL;
    }

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow->val;
}
int kthToLast2(struct ListNode* head, int k)
{
    int cont = 0;
    ListNode* cur = head;
    while (cur)
    {
        cont++;
        cur = cur->next;
    }

    int len = cont;
    int kk = len - k;
    cont = 0;
    cur = head;
    while (cur)
    {
        if (cont == kk)
        {
            break;
        }
        cont++;
        cur = cur->next;
    }

    return cur->val;
}

//�Ƴ�����Ԫ��
struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (head == NULL)
        return NULL;

    ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
    newHead->val = -1;
    newHead->next = NULL;

    ListNode* cur = head;
    ListNode* newTail = newHead;
    while (cur)
    {
        if (cur->val != val)
        {
            newTail->next = cur;
            newTail = newTail->next;
        }

        cur = cur->next;
    }

    newTail->next = NULL;

    return newHead->next;
}

//��ת����
struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL)
        return NULL;

    ListNode* n1 = NULL;
    ListNode* n2 = head;
    ListNode* n3 = head->next;

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

//�ϲ�������������
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    ListNode* l1 = list1;
    ListNode* l2 = list2;

    ListNode* list = (ListNode*)malloc(sizeof(ListNode));
    list->val = -1;
    list->next = NULL;
    ListNode* cur = list;

    while (l1 && l2)
    {
        if (l2->val < l1->val)
        {
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
        else
        {
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
    }

    if (l1)
    {
        cur->next = l1;
    }
    if (l2)
    {
        cur->next = l2;
    }

    return list->next;
}

//������м�ڵ�
struct ListNode* middleNode(struct ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

//���������Լɪ������
ListNode* BuyNode(int n)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = n;
    node->next = NULL;
    return node;
}

ListNode* CreatList(int n)
{
    ListNode* phead = BuyNode(1);
    ListNode* ptail = phead;

    for (size_t i = 2; i <= n; i++)
    {
        ptail->next = BuyNode(i);
        ptail = ptail->next;
    }

    ptail->next = phead;

    return ptail;
}


int ysf(int n, int m)
{
    int cont = 1;
    ListNode* prev = CreatList(n);
    ListNode* phead = prev->next;
    ListNode* pcur = phead;

    while (pcur->next != pcur)
    {
        prev = pcur;
        pcur = pcur->next;
        cont++;
        if (cont == m)
        {
            cont = 1;
            prev->next = pcur->next;
            free(pcur);
            pcur = prev->next;
        }
    }

    return pcur->val;
}

//�Ƴ�Ԫ��2��˫ָ�룬����
int removeElement2(int* nums, int numsSize, int val)
{
    //��ͷ��β�������飬�ҵ���һ�γ���nums[src]==val��ֵ���÷�val��ֵ������

    int dest = 0, src = 0;
    while (src < numsSize)
    {
        if (nums[src] == val)
            src++;
        else
            nums[dest++] = nums[src++];
    }

    return dest;
}

//�Ƴ�Ԫ��1
int removeElement1(int* nums, int numsSize, int val)
{
    int left = 0, right = numsSize - 1;

    while (left <= right)
    {
        if (nums[left] == val)
        {
            while (left <= right && nums[right] == val)
            {
                right--;
            }

            if (right < left)
            {
                break;
            }
            else
            {
                int tmp = nums[right];
                nums[right] = nums[left];
                nums[left] = tmp;

                right--;
            }
        }

        left++;

    }

    return left;

}

//�ϲ�������������
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int len1 = m - 1, len2 = nums2Size - 1;
    int len = nums1Size - 1;

    while (len1 >= 0 && len2 >= 0)
    {
        if (nums1[len1] > nums2[len2])
        {
            nums1[len] = nums1[len1];
            len1--;
        }
        else
        {
            nums1[len] = nums2[len2];
            len2--;
        }

        len--;
    }

    while (len1 >= 0)
    {
        nums1[len] = nums1[len1];
        len1--;
        len--;
    }

    while (len2 >= 0)
    {
        nums1[len] = nums2[len2];
        len2--;
        len--;
    }


}

int main()
{



	return 0;
}