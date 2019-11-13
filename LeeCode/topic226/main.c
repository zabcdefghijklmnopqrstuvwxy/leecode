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
* 先序遍历整个树然后将左右子结点交换即可
*/

struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL)
    {
        return NULL;
    }

    struct TreeNode *pnode;
    pnode = root->left;
    root->left = root->right;
    root->right = pnode; 

    invertTree(root->left);
    invertTree(root->right);

    return root;
}