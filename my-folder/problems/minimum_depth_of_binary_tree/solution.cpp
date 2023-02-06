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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        cout<<left<<endl;
        cout<<right<<endl;
        if(left==0 && right !=0)
            return right+1;
        else if(right==0 && left != 0)
            return left+1;
        int ans=min(left,right)+1;
        return ans;
    }
};