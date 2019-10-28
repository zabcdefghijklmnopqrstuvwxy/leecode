#include<stdio.h>
#include<stdbool.h>

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};




bool hasPathSum(struct TreeNode* root, int sum)
{
    if(NULL == root)
    {
    	return false;
    }	    

    if(root->left == NULL && root->right == NULL)
    {
	if(root->val == sum)
	{
	    return true;
	}
	else
	{
	    return false;
	}	
    }
    else
    {
    	if(root->left)
	{
	    root->left->val = root->val + root->left->val;
	}

	if(root->right)
	{
	    root->right->val = root->val + root->right->val;
	}
    }

    return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);
}

int main(void)
{
    struct TreeNode root;

    struct TreeNode l1;
    struct TreeNode l2;
    struct TreeNode r1;
    struct TreeNode r2;

    root.val = 1;
    root.left = &l1;
    root.right = &r1;

    l1.val = 2;
    l1.left = &l2;
    l1.right = NULL;

    l2.val = 3;
    l2.left = NULL;
    l2.right = NULL;

    r1.val = 4;
    r1.left = &r2;
    r1.right = NULL;

    r2.val = 5;
    r2.left = NULL;
    r2.right = NULL;


    if(hasPathSum(&root, 20))
    {
    	printf("path sum is true\n");
    }
    else
    {
    	printf("path sum is false\n");
    }

    return 0;
}

