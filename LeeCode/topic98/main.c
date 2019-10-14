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

#if 0
bool isValidBST(struct TreeNode* root)
{
    if(NULL == root)
    {
        return false;
    }

    while()


    if(root->left != NULL)
    {
	    if(root->left->val >= root->val)
        {
            return false;
        }
    }

    if(root->right != NULL)
    {
	    if(root->right->val <= root->val)
        {
            return false;
        }
    }

    return isValidBST(root->left) && isValidBST(root->right);
}
#endif

bool isValidBST(struct TreeNode* root)
{
    static int nFlag = 1;
    static int nMiddVal = 0;
    
    if(NULL == root)
    {
        return true;
    }

    if(nFlag == 1)
    {
        nFlag = 0;
        nMiddVal = root->val;
    }
    
    if(root->left != NULL)
    {
	    if(root->left->val >= root->val || root->left->val >= nMiddVal)
        {
            return false;
        }
    }

    if(root->right != NULL)
    {
	    if(root->right->val <= root->val || root->right->val <= nMiddVal)
        {
            return false;
        }
    }

    return isValidBST(root->left) && isValidBST(root->right);
}

int main(void)
{
    int nRet = 0;
        
    struct TreeNode p0;
    struct TreeNode p1;
    struct TreeNode p2;


    p0.val = 0;
    p0.left = &p1;
    p0.right = NULL;
    p1.val = 1;
    p1.left = NULL;
    p1.right = NULL;
    p2.val = 1;
    p2.left = NULL;
    p2.right = NULL;   

    nRet = isValidBST(&p0);

    if(true == nRet)
    {
        printf("p and q is bst tree\n");
    }
    else
    {
        printf("p and q is not bst tree\n");
    }

    return 0;
}
