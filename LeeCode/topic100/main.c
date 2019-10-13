#include<stdio.h>
#include<stdbool.h>

/**
 * Definition for a binary tree node.
*/
struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if((p == NULL && q != NULL) || (p != NULL && q == NULL))
    {
        return false;
    }
    
    if(p == NULL && q == NULL)
    {
        return true;
    }

    if(p->val != q->val)
    {
        return false;
    }
    
    if(false == isSameTree(p->left,q->left))
    {
        return false;
    }

    if(false == isSameTree(p->right,q->right))
    {
        return false;
    }

    return true;
}

int main(void)
{
    int nRet = 0;
        
    struct TreeNode p0;
    struct TreeNode p1;
    struct TreeNode p2;
    struct TreeNode q0;
    struct TreeNode q1;
    struct TreeNode q2;

    p0.val = 1;
    p0.left = &p1;
    p0.right = &p2;
    p1.val = 2;
    p1.left = NULL;
    p1.right = NULL;
    p2.val = 3;
    p2.left = NULL;
    p2.right = NULL;

    q0.val = 1;
    q0.left = &q1;
    q0.right = &q2;
    q1.val = 2;
    q1.left = NULL;
    q1.right = NULL;
    q2.val = 3;
    q2.left = NULL;
    q2.right = NULL;

    nRet = isSameTree(&p0,&q0);

    if(true == nRet)
    {
        printf("p and q is same tree\n");
    }
    else
    {
        printf("p and q is diff tree\n");
    }

    return 0;
}
