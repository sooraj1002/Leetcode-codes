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

    int size(ListNode* head,ListNode* &tail){
        int count=0;
        while(head != NULL)
        {
            count++;
            tail=head;
            head=head->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail=NULL;
        if(head==NULL || head->next==nullptr || k==0)
        return head;
        int n=size(head,tail);
        int a=k%n;
        int b=n-a;
        if(k%n==0)
        return head;
        auto t=head;
        while(--b)
        {
            t=t->next;
        }
        auto t1=t->next;
        t->next=NULL;
        tail->next=head;
        return t1;
    }
};