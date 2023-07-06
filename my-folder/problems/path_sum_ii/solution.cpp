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
    void solve(TreeNode* root,int target,vector<vector<int>> &ans,vector<int> temp){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(target==root->val)
                ans.push_back(temp);
            return;
        }
        solve(root->left,target-root->val,ans,temp);
        solve(root->right,target-root->val,ans,temp);
        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root,target,ans,temp);
        return ans;
    }
};