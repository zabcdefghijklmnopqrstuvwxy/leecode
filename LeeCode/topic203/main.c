#include<stdio.h>
#include<stdbool.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *pNode = head;
    struct ListNode *pCur = NULL;
    struct ListNode *pPre = NULL;
    if(NULL == head)
    {
        return NULL;    
    }
    
    while(pNode)
    {
        if(pNode->val != val)
        {
            break;
        }
        else
        {
            pNode = pNode->next;
        }
    }
    
    pCur = pNode;
    pPre = pNode;
    
    while(pCur)
    {
        if(pCur->val == val)
        {
            pPre->next = pCur->next;
        }
        else
        {
            pPre = pCur;
        }
        
        pCur = pCur->next;                        
    }
    
    return pNode;
}
