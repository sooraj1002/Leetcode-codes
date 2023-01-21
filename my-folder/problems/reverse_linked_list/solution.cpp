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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
        return head;
        auto it=head->next;
        head->next=NULL;
        while(it != NULL)
        {
            auto temp=head;
            head=it;
            it=it->next;
            head->next=temp;
        }
        return head;
    }
};