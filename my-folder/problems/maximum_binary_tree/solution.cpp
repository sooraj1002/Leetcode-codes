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
// class Solution {
// public:
//     int findMax(vector<int> nums){
//         int index=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]>nums[index])
//                 index=i;
//         }
//         return index;
//     }
//     TreeNode* construct(vector<int> &nums, vector::iterator start){
//         if(nums.size()==0)
//             return NULL;
//         int m=findMax(nums);
//         TreeNode* root=new TreeNode(nums[m]);
//         vector<int> left,right;
//         for(int i=0;i<nums.size();i++){
//             if(i<m)
//                 left.push_back(nums[i]);
//             if(i>m)
//                 right.push_back(nums[i]);
//         }
//         auto l=construct(left);
//         auto r=construct(right);
//         root->left=l;
//         root->right=r;
//         return root;
//     }
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         return construct(nums);
//     }
// };


class Solution {
public:
int maxi(vector<int>&nums,int start,int end)
{
    int ans=start;
    for(int i=start;i<=end;i++)
    {
       if(nums[i]>nums[ans])
       {
           ans=i;
       }
    }
    cout<<"start "<<start<<" end "<<end<<endl;
    cout<<nums[ans]<<endl;
    return ans;
}
TreeNode*solve(vector<int>&nums,int start,int end,int count)
{
    if(count>=nums.size() || start>end)
    {
        return NULL;
    }

    int index=maxi(nums,start,end);

    TreeNode*root=new TreeNode(nums[index]);
    root->left=solve(nums,start,index-1,count+1);
    root->right=solve(nums,index+1,end,count+1);

    return root;
    
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int count=0;
       TreeNode*ans= solve(nums,start,end,count);
       return ans;

    }
};