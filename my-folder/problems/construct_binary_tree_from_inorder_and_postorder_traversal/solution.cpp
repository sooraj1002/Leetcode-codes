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
    void createmap(vector<int> inorder,map<int,int> &mp){
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,map<int,int> &nodetoindex,int inorderstart,int inorderend,int &index){
        if(index < 0 || inorderstart>inorderend)
            return NULL;
        
        int element=postorder[index];
        TreeNode* root=new TreeNode(element);
        index--;
        int pos=nodetoindex[element];
        root->right=build(inorder,postorder,nodetoindex,pos+1,inorderend,index);
        root->left=build(inorder,postorder,nodetoindex,inorderstart,pos-1,index);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> nodetoindex;
        createmap(inorder,nodetoindex);

        int index=postorder.size()-1;
        TreeNode* root=build(inorder,postorder,nodetoindex,0,inorder.size()-1,index);
        return root;
    }
};