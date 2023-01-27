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

    ListNode* middle(ListNode* head,ListNode* &prev){
        auto fast=head,slow=head;
        while(fast != NULL && fast->next != NULL){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        
        return slow;
    }

    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev=NULL;
        if(head->next==NULL)
        return NULL;
        ListNode* mid=middle(head,prev);
        prev->next=mid->next;
        delete mid;
        
        return head;
    }
};