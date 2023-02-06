/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void traversal(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        int k=0;
        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();
            if(temp==NULL){
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                if(!q.empty())
                    temp->next=q.front();
                if(q.empty())
                    temp->next=NULL;
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
        }
    }
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        traversal(root);
        return root;
    }
};