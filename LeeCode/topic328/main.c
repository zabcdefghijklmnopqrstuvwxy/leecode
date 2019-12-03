#include<stdio.h>

/**
* @brief链表交替连接即可
*/
struct ListNode* oddEvenList(struct ListNode* head)
{ 
    if(NULL == head)
    {
        return NULL;
    }

    struct ListNode *podd = head;
    struct ListNode *pevenh = head->next;
    struct ListNode *peven = head->next;

    while(podd != NULL && peven != NULL)
    {
        if(podd)
        {
            if(peven)
            {
                podd->next = peven->next;
            }
            else
            {
                podd->next = NULL;
            }
        }

        if(podd)
        {
            podd = podd->next;
        }

        if(peven)
        {
            if(podd)
            {
                peven->next = podd->next;
            }
            else
            {
                peven->next = NULL;
            }       
        }
        if(peven)
        {
             peven = peven->next;
        }
    }

    podd = head;
    while(podd->next)
    {
        podd = podd->next;
    }
    podd->next = pevenh;

    return head;
}