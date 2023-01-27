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

    void delbyval(ListNode* head){
        ListNode* prev=head;
        head=head->next;
        while(head !=NULL){
            // cout<<"yee "<<endl;
            // cout<<head->val<<endl;
            if(head->val==0)
            {
                // cout<<"F"<<endl;
                head=head->next;
            }
            else
            {
                // cout<<"K"<<endl;
                prev->next=head;
                head=head->next;
                prev=prev->next;
            }
            prev->next=NULL;
        }
    }

    ListNode* mergeNodes(ListNode* head) {
        auto it=head->next;
        while(it != NULL)
        {
            int temp=0;
            auto t=it;
            while(it->val != 0)
            {
                // cout<<"ye"<<endl;
                // cout<<it->val<<endl;
                temp=temp+it->val;
                it=it->next;
            }
            t->val=temp;
            t->next=it;
            it=it->next;
        }
        head=head->next;
        delbyval(head);
        return head;
    }
};