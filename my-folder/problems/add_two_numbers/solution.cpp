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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* head=new ListNode();
        ListNode* ans=head;

        int n=l1->val+l2->val;
        if(n>9)
        {
            carry=1;
            n=n-10;
        }
        else
        carry=0;
        ans->val=n;
        l1=l1->next;
        l2=l2->next;

        while(l1 != NULL && l2 !=NULL)
        {
            int n=l1->val+l2->val+carry;
            if(n>9)
            {
                carry=1;
                n=n-10;
            }
            else
            carry=0;
            ListNode* temp=new ListNode(n);
            head->next=temp; 
            head=head->next; 
            l1=l1->next;
            l2=l2->next;
        }
        while(l1 != NULL)
        {
            int n=l1->val+carry;
            if(n>9)
            {
                carry=1;
                n -=10;
            }
            else
            carry=0;
            ListNode* temp=new ListNode(n);
            head->next=temp; 
            head=head->next; 
            l1=l1->next;
        }
        while(l2 != NULL)
        {
            int n=l2->val+carry;
            if(n>9)
            {
                carry=1;
                n -=10;
            }
            else
            carry=0;
            ListNode* temp=new ListNode(n);
            head->next=temp; 
            head=head->next; 
            l2=l2->next;
        }
        if(carry==1)
        {
            ListNode* temp=new ListNode(1);
            head->next=temp; 
        }
        return ans;
    }
};