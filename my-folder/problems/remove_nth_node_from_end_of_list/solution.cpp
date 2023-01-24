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
    int len(ListNode*  head)
    {
        auto temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* nodetbd(ListNode* head,int n)
    {
        int count=0;
        auto temp=head->next;
        auto ans=head;
        if(n==1){
            head=head->next;
            return head;
        }
        while(count<n-2 && temp != NULL){
            cout<<temp->val<<endl;
            temp=temp->next;
            head=head->next;
            count++;
        }
        if(temp==NULL)
        {
            return head;
        }
        temp=temp->next;
        head->next=temp;
        return ans;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int a=len(head)-n+1;
        // cout<<a<<endl;
        return nodetbd(head,a);
    }
};