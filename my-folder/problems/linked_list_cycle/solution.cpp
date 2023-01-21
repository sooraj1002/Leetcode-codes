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
    bool hasCycle(ListNode *head) {
        
        if(head==NULL)
        return false;
        if(head->next==NULL)
        return false;

        auto slow=head;
        auto fast=head->next;
        while(fast->next != NULL)
        {
            if(slow==fast->next)
            return true;
            fast=fast->next->next;
            slow=slow->next;
            if(fast==NULL)
            break;
        }
        return false;

    }
};