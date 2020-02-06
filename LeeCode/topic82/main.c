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
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *pre = dummy;
    struct ListNode *pcur = head;
    pre->next = head;

    while(pcur != NULL && pcur->next != NULL)
    {
        while(pcur->next != NULL && pcur->val == pcur->next->val)
        {
            pcur = pcur->next;
        }
     
        if(pre->next != pcur)
        {
            pre->next = pcur->next;
            pcur = pre->next;
        }
        else
        {
            pre = pcur;
            pcur = pcur->next;
        }       
    }

    return dummy->next;
}

