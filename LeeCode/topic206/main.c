#include<stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
/**
* @brief 递归法，交换前后节点指针，将最后的节点指针层层返回给最开始。
*/
struct ListNode* reverseList(struct ListNode* head)
{
    if( head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *pnode = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return pnode;
}