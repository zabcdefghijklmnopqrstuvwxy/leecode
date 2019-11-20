#include<stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    if(m == n)
    {
        return head; // 不用管的情况
    }

    struct ListNode h = {0, head}; //设置一个头节点,处理m=1的情况
    struct ListNode* p = &h;
    struct ListNode* tail;

    for(int i = 1; i <= n; i++)
    {
        if(i < m) // p指向第n-1个节点位置
        {
            p = p->next;
        }
        else if(i == m) // tail指向第第n个节点，这个节点反转后处在反转部分的最后一个
        {
            tail = p->next;
        }
        else 
        { //每次将tail后面一个节点拿出来，放在p后面
            struct ListNode* item = tail->next;
            tail->next = tail->next->next;
            item->next = p->next;
            p->next = item;
        }
    }
    return h.next;
}