#include<stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode dumpnode;
    struct ListNode *pre = NULL;
    dumpnode.next = head;
    
    while(head != NULL && head->next != NULL)
    {
        if(head->val < head->next->val)
        {
            head = head->next;
            continue;
        }
        pre = &dumpnode;

        while(pre->next->val < head->next->val)
        {
            pre = pre->next;
        }

        struct ListNode *currnode = head->next;
        head->next = currnode->next;
        currnode->next = pre->next;
        pre->next = currnode;
    }

    return dumpnode.next;
}