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
    void traverse(TreeNode* root,vector<vector<int>> &ans,vector<int> t)
    {
        if(root==NULL)
            return;
        t.push_back(root->val);
        traverse(root->left,ans,t);
        traverse(root->right,ans,t);
        if(!root->left && !root->right)
        ans.push_back(t);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> t;
        vector<vector<int>> ans;
        traverse(root,ans,t);
        vector<string> main;

        // for(auto i:ans)
        // {
        //     for(auto j:i)
        //         cout<<j<<"  ";
        //     cout<<endl;
        // }
        for(int i=0;i<ans.size();i++)
        {
            string temp;
            for(int j=0;j<ans[i].size();j++)
            {
                // int a=ans[i][j];
                string str=to_string(ans[i][j]);
                if(j==0)
                    temp+=str;
                else{
                    temp.push_back('-');
                    temp.push_back('>');
                    temp+=str;
                }
            }
            main.push_back(temp);
        }
        return main;
    }
};