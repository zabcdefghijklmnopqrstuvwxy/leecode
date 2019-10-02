#include<stdio.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *SlowNode = head;
    struct ListNode *FastNode = head;
    int nCnt = 0;

    while(FastNode->next != NULL)
    {
        nCnt++;
        if(nCnt > n)
        {
            SlowNode = SlowNode->next;
            FastNode = FastNode->next;
        }
        else
        {
            FastNode = FastNode->next;
        }
    }

    if(nCnt < 1)
    {
        return NULL;
    }

    if(nCnt == (n - 1))
    {
        return head->next;
    }

    SlowNode->next = SlowNode->next->next;

    return head;
}

int main(void)
{
    int i = 0;
    struct ListNode l1,l2,l3,l4,l5;
    struct ListNode *ret = NULL;
    l1.val = 1;
    l1.next = &l2;
    l2.val = 2;
    l2.next = &l3;
    l3.val = 3;
    l3.next = &l4;
    l4.val = 4;
    l4.next = &l5;
    l5.val = 5;
    l5.next = NULL;

    ret = removeNthFromEnd(&l1, 1);

    while(ret)
    {
        printf("%d\t",ret->val);
        ret = ret->next;
    }

    return 0;
}
