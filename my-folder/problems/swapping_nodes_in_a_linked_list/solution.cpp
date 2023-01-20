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
    ListNode* swapNodes(ListNode* head, int k) {
        auto it=head;
        int n=0;
        while(it != NULL)
        {
            n++;
            it=it->next;
        }
        it=head;
        int last=n-k+1;
        ListNode* t1;
        ListNode* t2;
        while(last>0)
        {
            t1=it;
            it=it->next;
            last--;
        }
        it=head;
        while(k>0)
        {
            t2=it;
            it=it->next;
            k--;
        }
        int temp=t1->val;
        t1->val=t2->val;
        t2->val=temp;
        return head;
    }
};