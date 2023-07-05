class Solution {
public:
    //ITERATIVE SOLUTION
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        for(int i1=nums1.size()-1;i1>=0;i1--){
            for(int i2=nums2.size()-1;i2>=0;i2--){
                if(nums1[i1]==nums2[i2])
                    dp[i1][i2]=1+dp[i1+1][i2+1];
                else
                    dp[i1][i2]=max(dp[i1+1][i2],dp[i1][i2+1]);
            }
        }
        return dp[0][0];
    }
    //RECURSIVE SOLUTION
    // int solve(vector<int> &nums1,vector<int> &nums2,int i1,int i2,vector<vector<int>> &dp){
    //     if (i1==nums1.size() || i2==nums2.size()){
    //         return 0;
    //     }
    //     if(dp[i1][i2] != -1)return dp[i1][i2];
    //     if(nums1[i1]==nums2[i2])
    //         return dp[i1][i2]=1+solve(nums1,nums2,i1+1,i2+1,dp);
        
    //     return dp[i1][i2]=max(solve(nums1,nums2,i1+1,i2,dp),solve(nums1,nums2,i1,i2+1,dp));
    // }
    // int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    //     vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
    //     return solve(nums1,nums2,0,0,dp);
    // }
};