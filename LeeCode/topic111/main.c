#include<stdio.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root){
    int nLeft = 0;
    int nRight = 0;

    if(root == NULL)
    {
        return 0;
    }

    nLeft = minDepth(root->left);
    nRight = minDepth(root->right);

    if (root->left == NULL || root->right == NULL)
    {
        return nLeft + nRight + 1;
    }

    return (nLeft > nRight ? nRight : nLeft) + 1;
}