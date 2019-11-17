#include<stdio.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
* @brief 递归
*/

int maxDepth(struct TreeNode* root){
    int nLeftDepth = 0;
    int nRightDepth = 0;

    if(root == NULL)
    {
        return 0;
    }

    nLeftDepth = maxDepth(root->left);
    nRightDepth = maxDepth(root->right);

    return (nLeftDepth > nRightDepth ? nLeftDepth : nRightDepth) + 1;
}