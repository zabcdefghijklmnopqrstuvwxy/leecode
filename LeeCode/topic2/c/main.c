#include<stdio.h>

struct ListNode {
      int val;
      struct ListNode *next;
};

int c = 0;

/**
@brief 递归累加
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	if(l1==NULL&&l2==NULL&&c==0)return NULL;
    l1!=NULL?(c+=l1->val,l1=l1->next):(c+=0);
    l2!=NULL?(c+=l2->val,l2=l2->next):(c+=0);
    struct ListNode *cur=(struct ListNode *)malloc(sizeof(struct ListNode));
    cur->val=c%10;
    c=c/10;
    cur->next=addTwoNumbers(l1,l2);
    return cur;
}


int main(void)
{
    int i = 0;
    struct ListNode l1[6] = {0};
    struct ListNode l2[6] = {0};
    struct ListNode* ret = NULL;

    for(i = 0; i < 5; i++)
    {
        l1[i].val = i+1;
        l1[i].next = &l1[i+1];
        l2[i].val = i+1;
        l2[i].next = &l2[i+1];
    }

    ret = addTwoNumbers(l1,l2);

    printf("sum list node is:");
    while(ret)
    {
        printf("%d\t",ret->val);
        ret = ret->next;
    }

    return 0;
}

