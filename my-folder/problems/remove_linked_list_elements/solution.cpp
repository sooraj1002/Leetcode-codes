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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
        return head;

        while(head != NULL && head->val == val)
        head=head->next;
        if(head==NULL)
        return head;

        auto ans =head;
        auto fast=head->next;
        while(fast != NULL)
        {
            if(fast->val== val)
            {
                // cout<<"ye"<<endl;
                head->next=fast->next;
                fast=fast->next;
                continue;
            }
            head=head->next;
            // if(fast==NULL)
            // break;
            fast=fast->next;
        }
        // cout<<head->val;
        return ans;
    }
};