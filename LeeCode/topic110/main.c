#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/**
 * Definition for a binary tree node.
*/
struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};

int Balanced(struct TreeNode* root)
{
    int nLeft = 0;
    int nRight = 0;

    if(NULL == root)
    {
        return 0;
    }
    
    nLeft = Balanced(root->left);
    
    if(-1 == nLeft)
    {
        return -1;
    }

    nRight = Balanced(root->right);

    if(-1 == nRight)
    {
        return -1;
    }

    if(abs(nLeft - nRight) > 1)
    {
        return -1;
    }

    return (nLeft > nRight ? nLeft : nRight) + 1;
}

bool isBalanced(struct TreeNode* root)
{
    return Balanced(root) != -1;
}

int main(void)
{
    struct TreeNode root;
    struct TreeNode l0;
    struct TreeNode r0;
    struct TreeNode r1;
    struct TreeNode r2;

    root.val = 3;
    root.left = &l0;
    root.right = &r0;

    l0.val = 9;
    l0.left = NULL;
    l0.right = NULL;

    r0.val = 20;
    r0.left = &r1;
    r0.right = &r2;

    r1.val = 15;
    r1.left = NULL;
    r1.right = NULL;

    r2.val = 7;
    r2.left = NULL;
    r2.right = NULL;

    if(isBalanced(&root))
    {
        printf("This is balance tree");
    }
    else
    {
        printf("This is not balance tree");
    }
	
	return 0;
}
