/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* find(Node* target,Node* parent,Node* copy){
        auto f=parent;
        auto f1=copy;
        while(f!= NULL && f!= target){
            f=f->next;
            f1=f1->next;
            if(f ==target){
                return f1;
            }
        }
        return NULL;
    }
    Node* copyRandomList(Node* head) {
        auto t=head;
        auto dummy= new Node(0);
        auto t1=dummy;
        vector<int> temp;
        while(t != NULL){
            auto temp= new Node(t->val);
            t1->next=temp;
            t1=t1->next;
            t=t->next;
        }
        // cout<<"hi"<<endl;
        t=head;
        t1=dummy->next;
        while(t != NULL){
            if(t->random == NULL){
                t1->random==NULL;
            }
            else if(t->random==head){
                t1->random=dummy->next;
            }
            else{
                t1->random=find(t->random,head,dummy->next);
            }
            t=t->next;
            t1=t1->next;
        }

        return dummy->next;
    }
};