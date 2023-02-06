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
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        int ans=max(right,left)+1;
        // cout<<ans<<endl;
        return ans;
    }
    pair<bool,int> isBalancedFast(TreeNode* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<bool,int> left= isBalancedFast(root->left);
        pair<bool,int> right= isBalancedFast(root->right);

        bool l=left.first;
        bool r=right.first;
        bool diff=(abs(left.second-right.second))<=1;

        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;

        if(l && r && diff)
            ans.first=1;
        else
            ans.first=0;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};