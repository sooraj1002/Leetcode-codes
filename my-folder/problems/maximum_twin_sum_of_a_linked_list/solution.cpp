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
    int pairSum(ListNode* head) {
        vector<int> v;
        while(head != NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        int start=0;
        int end=v.size()-1;
        int max=INT_MIN;
        while(start<end)
        {
            if(v[start]+v[end]>max)
            max=v[start]+v[end];
            start++;
            end--;
        }
        return max;
    }
};