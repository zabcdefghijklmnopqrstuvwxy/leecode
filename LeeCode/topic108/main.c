#include<stdio.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* BuildBst(int *nums,int start,int end)
{
    if(start > end)
    {
        return NULL;
    }    
    
    struct TreeNode *pnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    pnode->val = nums[(end + start) >> 1];
    pnode->left = BuildBst(nums, start, ((end + start) >> 1) - 1);
    pnode->right = BuildBst(nums, ((end + start) >> 1) + 1,end);
    
    return pnode;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return BuildBst(nums, 0, numsSize - 1);
}