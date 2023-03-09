/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> mp;
        auto it=head;
        ListNode* ans=NULL;
        while(it && it->next)
        {
            mp[it]++;
            if(mp[it]==2){
                ans=it;
                break;
            }
            it=it->next;
        }
        return ans;
    }
};