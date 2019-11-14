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
*@brief 通过对自身进行镜像来验证是否左右相同
*/

bool isMirror(struct TreeNode*rl,struct TreeNode *rr)
{
    if(rl == NULL && rr == NULL)
    {
        return true;
    }

    if((rl == NULL && rr != NULL) || (rl != NULL && rr == NULL))
    {
        return false;
    }

    return ((rl->val == rr->val) && isMirror(rl->left,rr->right) && isMirror(rl->right,rr->left));
}


bool isSymmetric(struct TreeNode* root){
    return isMirror(root,root);
}