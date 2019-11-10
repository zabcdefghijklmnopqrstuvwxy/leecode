#include<stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *pnode = node;
    struct ListNode *ppre = NULL;
    if(node == NULL)
    {
        return ;
    }
    
    while(pnode->next)
    {
        ppre = pnode;
        pnode->val = pnode->next->val;
        pnode = pnode->next;
    }
    
    ppre->next = NULL;
}