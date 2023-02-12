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

    int find(vector<int> inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element)
                return i;
        }
        return -1;
    }
    TreeNode* build(vector<int> &preorder, vector<int> &inorder,int &index,int inorderstart,int inorderend){
        if(index==preorder.size() || inorderstart>inorderend)
            return NULL;
        
        int element=preorder[index];
        index++;
        TreeNode* root=new TreeNode(element);
        int pos=find(inorder,element);

        root->left=build(preorder,inorder,index,inorderstart,pos-1);
        root->right=build(preorder,inorder,index,pos+1,inorderend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        auto ans=build(preorder,inorder,index,0,inorder.size()-1);
        return ans;
    }
};