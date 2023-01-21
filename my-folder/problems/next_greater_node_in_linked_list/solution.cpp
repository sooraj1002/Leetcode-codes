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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        while(head != NULL)
        {
            auto it=head;
            while(it != NULL)
            {
                if(it->val>head->val)
                {
                    ans.push_back(it->val);
                    break;
                }
                else
                it=it->next;
                if(it == NULL)
                ans.push_back(0);
            }
            head=head->next;
        }
        return ans;
    }
};