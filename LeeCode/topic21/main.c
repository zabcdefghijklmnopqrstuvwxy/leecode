#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }

    if(l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}

int main(void)
{
    struct ListNode l11;
    struct ListNode l12;
    struct ListNode l2;
    struct ListNode l3;
    struct ListNode l4;

    struct ListNode *ret = NULL;

    l11.val = 1;
    l11.next = &l2;
    l2.val = 2;
    l2.next = & l4;
    l4.val = 4;
    l4.next = NULL;

    l12.val = 1;
    l12.next = &l3;
    l3.val = 3;
    l3.next = &l4;
    
    ret = mergeTwoLists(&l11, &l12);

    while(ret != NULL)
    {
        printf("%d->",ret->val);
        ret = ret->next;
    }

    printf("\n");

    return 0;
}
