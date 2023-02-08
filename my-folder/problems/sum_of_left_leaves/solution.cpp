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
    void traverse(TreeNode* root,bool yes,int &ans){
        if(root==NULL)
            return;
        traverse(root->left,true,ans);
        if(root->left==NULL && root->right==NULL && yes)
            ans+=root->val;
        traverse(root->right,false,ans);
        cout<<"end "<<ans<<endl;
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        traverse(root,false,ans);
        return ans;
    }
};