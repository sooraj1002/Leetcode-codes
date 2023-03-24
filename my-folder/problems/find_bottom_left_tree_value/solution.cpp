/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* ans=root;
        int flag=0;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            if(temp==NULL){
                flag=1;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                // cout<<temp->val<<endl;
                if(flag==1){
                    // cout<<"above is ans"<<endl;
                    ans=temp;
                    flag=0;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return ans->val;
    }
};