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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL){
            return NULL;
        }
        ListNode* dummy=new ListNode();
        ListNode* ans=new ListNode();
        auto t1=ans;
        auto t2=dummy;
        while(head != NULL){
        //     cout<<"h "<<endl;
            if(head->val<x){
                t1->next=head;
                head=head->next;
                t1=t1->next;
                t1->next=NULL;
            }
            else{
                t2->next=head;
                head=head->next;
                t2=t2->next;
                t2->next=NULL;
            }

        }
        t1->next=dummy->next;
        return ans->next;
    }
};