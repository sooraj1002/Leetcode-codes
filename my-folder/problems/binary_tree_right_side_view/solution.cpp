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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode*,int> p=make_pair(root,0);
        q.push(p);
        while(!q.empty())
        {
            pair<TreeNode*,int> temp=q.front();
            q.pop();
            auto frontNode=temp.first;
            int vdist=temp.second;
            
            mp[vdist].push_back(frontNode->val);
            if(frontNode->left)
                q.push(make_pair(frontNode->left,vdist+1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right,vdist+1));
        }
        for(auto i:mp)
        {
            ans.push_back(i.second.back());
        }
        return ans;
    }
};