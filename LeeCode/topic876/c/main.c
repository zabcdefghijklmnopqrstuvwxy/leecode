/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
* @brief 快慢指针处理
*/
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slownode = head;
    struct ListNode *fastnode = head;

    while(fastnode != NULL && fastnode->next != NULL)
    {
        slownode = slownode->next;
        fastnode = fastnode->next->next;
    }

    return slownode;
}