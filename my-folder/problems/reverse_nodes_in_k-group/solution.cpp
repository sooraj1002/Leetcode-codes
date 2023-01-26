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

    int check(ListNode* head,int k)
    {
        auto it=head;
        int count=0;
        while(it != NULL)
        {
            count++;
            it=it->next;
        }
        return count;
    }

    void rev(ListNode* prev,ListNode* head,int k,int groups)
    {
        auto it1=head;
        int k1=k;
        while(--k1)
        {
            it1=it1->next;
        }
        auto store=it1->next;
        it1->next=NULL;
        
        auto tem=head;
        auto it=head->next;
        head->next=NULL;
        while(it != NULL)
        {
            auto temp=head;
            head=it;
            it=it->next;
            head->next=temp;
        }
        tem->next=store;
        prev->next=it1;
        groups--;
        if(groups>0)
        rev(tem,store,k,groups);
        if(groups==0)
        return;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        auto a=check(head,k);
        int groups=a/k,k1=k;
        // cout<<"groups  "<<groups<<endl;
        auto it1=head;
        while(--k1)
        {
            it1=it1->next;
        }
        
        auto store=it1->next;
        it1->next=NULL;
        
        auto tem=head;
        auto it=head->next;
        head->next=NULL;
        while(it != NULL)
        {
            auto temp=head;
            head=it;
            it=it->next;
            head->next=temp;
        }
        tem->next=store;
        groups --;
        if(groups>0)
        rev(tem,store,k,groups);
        
        return head;
    }
};