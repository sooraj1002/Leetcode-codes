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
    void traverse(TreeNode* root,int &sum,bool &ans,int target){
        if(root==NULL)
            return;
            
        sum +=root->val;
        if (sum==target && !root->left && !root->right)
            ans=true;
        traverse(root->left,sum,ans,target);
        traverse(root->right,sum,ans,target);
        sum-=root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans=0;
        int sum=0;
        traverse(root,sum,ans,targetSum);
        return ans;
    }
};