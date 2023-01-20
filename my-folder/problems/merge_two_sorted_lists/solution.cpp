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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode();
        if(l2==NULL && l1==NULL)
        return l1;
        else if(l1 ==NULL)
        return l2;
        else if(l2==NULL)
        return l1;

        else if(l1->val<l2->val)
        {
            // cout<<"ye"<<endl;
            head=l1;
            l1=l1->next;
        }
        else
        {
            // cout<<"rip"<<endl;
            head=l2;
            l2=l2->next;
        }
        ListNode* ans=head;
        while((l1 != NULL && l2 != NULL))
        {
            if(l1->val<l2->val)
            {
                // cout<<"F"<<endl;
                // auto temp=l1->next;
                head->next=l1;
                l1=l1->next;
            }
            else
            {
                // cout<<"K"<<endl;
                // auto temp=l2->next;
                head->next=l2;
                l2=l2->next;
            }
            head=head->next;
        }
        while(l1 != NULL)
        {
            // cout<<"this"<<endl;
            head->next=l1;
            l1=l1->next;
            head=head->next;
        }
        while(l2 != NULL)
        {
            // cout<<"why"<<endl;
            head->next=l2;
            l2=l2->next;
            head=head->next;
        }
        return ans;
    }
};