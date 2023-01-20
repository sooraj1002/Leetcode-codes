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
    ListNode* deleteDuplicates(ListNode* head) {
        auto temp=head;
        auto ans=head;
        if(head==NULL)
        return head;
        head=head->next;
        while(head != NULL)
        {
            if (temp->val==head->val)
            {
                // // cout<<temp->next<<endl;
                // // cout<<head->next<<endl;
                // cout<<"ye"<<endl;
                temp->next=NULL;
                head=head->next;
            }
            else
            {
                // cout<<temp->next<<endl;
                // cout<<head->next<<endl;
                // cout<<"F"<<endl;
                temp->next=head;
                head=head->next;
                temp=temp->next;
            }
            // cout<<"val of temp   "<<temp->val<<endl;
            // cout<<"add of temp   "<<temp<<endl;
        }
        return ans;
    }
};