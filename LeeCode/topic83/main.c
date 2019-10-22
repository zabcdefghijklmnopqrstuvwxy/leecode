#include<stdio.h>

/*
 * Definition for singly-linked list.
 */
struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    int nVal = 0;
    struct ListNode* pcur = head;
    struct ListNode* ppre = head;
    if(NULL == head)
    {
        return NULL;
    }

    nVal = head->val - 1;
    while(pcur)
    {
        if(pcur->val == nVal)
        {
            ppre->next = ppre->next->next;
        }
        else
        {
            ppre = pcur;
            nVal = pcur->val; 
        }
        pcur = pcur->next;
    }

    return head;
}

int main(void)
{
    struct ListNode *phead = NULL;
    struct ListNode n0;
    struct ListNode n1;
    struct ListNode n2;
    struct ListNode n3;

    n0.val = 1;
    n0.next = &n1;
    n1.val = 1;
    n1.next = &n2;
    n2.val = 1;
    n2.next = &n3;
    n3.val = 1;
    n3.next = NULL;

    phead = &n0;

    printf("before delete duplicates\t");
    while(phead)
    {
        printf("%d\t",phead->val);
        phead = phead->next;
    }

    phead = deleteDuplicates(&n0);
    printf("\nafter delete duplicates\t");

    while(phead)
    {
        printf("%d\t",phead->val);
        phead = phead->next;
    }

    return 0;
}
