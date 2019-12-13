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

/*
*@brief 可以考虑用中序遍历的方式，数值符合升序则成功 
*/
bool isValidBST(struct TreeNode* root)
{
     bool result = true;
    struct TreeNode* node;
    
    if(!root) return true;
    // rule 3
    if(root->left){
        result &= isValidBST(root->left) && (root->val > root->left->val);
    }
    if(root->right){
        result &= isValidBST(root->right) && (root->val < root->right->val);
    }
    //rule 1
    if(result && root->left){
        node = root->left;
        while(node->right){
            node = node->right;
        }
        if(node->val >= root->val){
            return false;
        }
    }
    //rule 2
    if(result && root->right){
        node = root->right;
        while(node->left){
            node = node->left;
        }
        if(node->val <= root->val){
            return false;
        }
    }
    return result;
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
