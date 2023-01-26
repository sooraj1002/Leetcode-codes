/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        auto fast=head,slow=head;
        while(fast != NULL && fast->next != NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        auto prev=slow;
        slow=slow->next;
        prev->next=NULL;
        ListNode* temp;
        while(slow != NULL)
        {
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        while(prev != NULL)
        {
            if(head->val != prev->val)
            return 0;
            head=head->next;
            prev=prev->next;
        }
        return 1;
    }
};