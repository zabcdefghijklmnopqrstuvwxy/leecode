#include<stdio.h>

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* cut(struct ListNode* head, int n) {
    struct ListNode* p = head;
    while (--n && p) 
    {
        p = p->next;
    }

    if(!p) 
    {
        return NULL;
    }

    struct ListNode* next = p->next;

    p->next = NULL;

    return next;
}

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode dummyHead;
    dummyHead.val = 0;
    dummyHead.next = NULL;

    struct ListNode* p = &dummyHead;

    while (l1 && l2) 
    {
        if (l1->val < l2->val) 
        {
            p->next = l1;
            p = l1;
            l1 = l1->next;       
        } 
        else 
        {
            p->next = l2;
            p = l2;
            l2 = l2->next;
        }
    }

    p->next = l1 ? l1 : l2;
    return dummyHead.next;
}

struct ListNode* sortList(struct ListNode* head) 
{
    struct ListNode dummyHead;
    int length = 0;
    struct ListNode* p = head;

    dummyHead.val = 0;
    dummyHead.next = head;

    while(p) 
    {
        ++length;
        p = p->next;
    }

    for(int size = 1; size < length; size <<= 1) 
    {
        struct ListNode* cur = dummyHead.next;
        struct ListNode* tail = &dummyHead;
        
        while (cur) 
        {
            struct ListNode* left = cur;
            struct ListNode* right = cut(left, size); // left->@->@ right->@->@->@...
            cur = cut(right, size); // left->@->@ right->@->@  cur->@->...
        
            tail->next = merge(left, right);
            while(tail->next) 
            {
                tail = tail->next;
            }
        }
    }

    return dummyHead.next;
}

int main(void)
{
    struct ListNode tN0;
    struct ListNode tN1;
    struct ListNode tN2;
    struct ListNode tN3;
    struct ListNode tN4;

    struct ListNode *tHead = &tN0;
    
    tN0.val = 3;
    tN0.next = &tN1;
    tN1.val = 2;
    tN1.next = &tN2;
    tN2.val = 4;
    tN2.next = &tN3;
    tN3.val = 1;
    tN3.next = &tN4;
    tN4.val = 1;
    tN4.next = NULL;

    printf("list sorted before\t");
    while(tHead)
    {
        printf("%d\t",tHead->val);
        tHead = tHead->next;
    }
    
    tHead = sortList(&tN0);
    printf("list sorted after\t");
    while(tHead)
    {
        printf("%d\t",tHead->val);
        tHead = tHead->next;
    }

    return 0;
}
