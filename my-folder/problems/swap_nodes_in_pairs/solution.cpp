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

    void swap(ListNode* head,ListNode* second){
        // while(head->next != NULL)
        {
            head->next=second->next;
            second->next=head;

            cout<<"head val  "<<head->val<<endl;
            cout<<"second val  "<<second->val<<endl;

            auto t=head->next;
            if(t==NULL)
            return;
            if(t->next==NULL)
            return;
            head->next=t->next;
            swap(t,t->next);
        }
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        
        auto second=head->next;
        auto ans=second;
        swap(head,second);
        return ans;
    }
};