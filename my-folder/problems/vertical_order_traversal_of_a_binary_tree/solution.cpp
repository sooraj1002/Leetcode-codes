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

    void inorder(TreeNode* root,map<int,list<pair<int,int>>> &mp,int dist,int level)
    {
        if(root==NULL)
            return;
        inorder(root->left,mp,dist-1,level+1);
        pair<int,int> p=make_pair(level,root->val);
        mp[dist].push_back(p);
        inorder(root->right,mp,dist+1,level+1);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,list<pair<int,int>>> mp;
        int dist=0;
        inorder(root,mp,0,0);
        vector<vector<int>> ans;
        for(auto i:mp)
        {
            vector<int> t;
            int mini=INT_MAX;
            map<int,vector<int>> m1;
            for(auto j:i.second)
            {
                m1[j.first].push_back(j.second);
            }
            for(auto j:m1)
            {
                sort(j.second.begin(),j.second.end());
                for(auto k:j.second)
                    t.push_back(k);
            }
            ans.push_back(t);
        }
        return ans;
    }
};