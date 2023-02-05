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
    void inorder(TreeNode* root,int count,int &maxi){
    if(root==NULL)
        return;
    count++;
    inorder(root->left,count,maxi);
    if(root->left==NULL && root->right==NULL)
    {
        maxi=max(maxi,count);
        count=0;
    }
    inorder(root->right,count,maxi);
}
    int maxDepth(TreeNode* root) {
        int maxi=0;
        inorder(root,0,maxi);
        return maxi;
    }
};