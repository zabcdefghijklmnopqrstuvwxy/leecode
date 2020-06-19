/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int nCurry = 0;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = 0;
        if(NULL == l1 && NULL == l2 && nCurry == 0)
        {
            return NULL;
        }

        if(l1)
        {
            nCurry += l1->val;
            l1=l1->next;
        }

        if(l2)
        {
            nCurry += l2->val;
            l2=l2->next;
        }
    
        ListNode *pnode = new ListNode;
        pnode->val = nCurry % 10;
        nCurry/=10;
        pnode->next = addTwoNumbers(l1,l2);

        return pnode;
    }
};