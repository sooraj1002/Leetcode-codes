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
    void traversal(TreeNode* root,vector<vector<int>> &ans){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int k=0;
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            if(temp==NULL){
                vector<int> t;
                k++;
                ans.push_back(t);
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                ans[k].push_back(temp->val);
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        vector<int> t;
        ans.push_back(t);
        traversal(root,ans);
        ans.pop_back();
        return ans;
    }
};