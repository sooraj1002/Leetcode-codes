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


class cmp{
public:
    bool operator()(ListNode*a, ListNode *b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(auto i:lists){
            if(i != NULL)
                pq.push(i);
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            if(head==NULL){
                head=temp;
                tail=temp;
                if(temp->next){
                    pq.push(temp->next);
                }
            }
            else{
                tail->next=temp;
                tail=tail->next;
                if(tail->next){
                    pq.push(tail->next);
                }
            }
        }
        return head;

    }
};