/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto it=node->next;
        while(it->next != NULL)
        {
            node->val=it->val;
            it=it->next;
            node=node->next;
        }
        node->val=it->val;
        node->next=NULL;
    }
};