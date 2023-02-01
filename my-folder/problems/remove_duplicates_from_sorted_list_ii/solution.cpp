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

    void del(ListNode* head,ListNode* &prev){
        auto temp=head;
        if(temp==NULL)
        return;
        while(temp!=NULL)
        {
            int f=0;
            int t=temp->val;
            // cout<<t<<endl;
            if(temp->next != NULL && temp->next->val==t)
            {
                // cout<<"k"<<endl;
                f=1;
                while(temp !=NULL && temp->next !=NULL && temp->next->val==t)
                    temp=temp->next;
                temp=temp->next;
                prev->next=temp;
                del(temp,prev);
                return;
            }
            else
            {
                // cout<<"m"<<endl;
                prev->next=temp;
                prev=temp;
                temp=temp->next;
            }
        }
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(-101,head);
        ListNode* prev=dummy;
        del(head,prev);
        return dummy->next;
    }
};