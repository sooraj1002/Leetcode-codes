class Solution {
public:
    //ITERATIVE SOLUTION
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int index=n-1;index>=0;index--){
            for(int prev=index-1;prev>=-1;prev--){
                int not_take=dp[index+1][prev+1];
                int take=0;
                if(prev==-1 || nums[index]>nums[prev])
                    take=1+dp[index+1][index+1];
                dp[index][prev+1]=max(take,not_take);
            }
        }
        return dp[0][-1+1];
    }

    //RECURSIVE SOLUTIION #2
    // int solve(vector<int> &nums,int index,int prev,vector<vector<int>> &dp){
    //     if(index==nums.size()){
    //         return 0;
    //     }
    //     if(dp[index][prev+1] != -1)return dp[index][prev+1];

    //     int not_take=solve(nums,index+1,prev,dp);
    //     int take=0;
    //     if(prev==-1 || nums[index]>nums[prev])
    //         take=1+solve(nums,index+1,index,dp);
    //     return dp[index][prev+1]=max(take,not_take);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //     return solve(nums,0,-1,dp);
    // }


    // RECURSIVE SOLUTION
    //solve index will give us the max length of increasing subsequence till the given index
    // int solve(vector<int> &nums,int index,int prev,vector<vector<int>> &dp){
    //     if(index<0){
    //         return 0;
    //     }
    //     if(dp[index][prev] != -1)return dp[index][prev];

    //     int not_take=solve(nums,index-1,prev,dp);
    //     int take=0;
    //     if(prev==nums.size())
    //         take=1+solve(nums,index-1,index,dp);
    //     if(prev<nums.size() && nums[index]<nums[prev])
    //         take=1+solve(nums,index-1,index,dp);
    //     return dp[index][prev]=max(take,not_take);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //     return solve(nums,nums.size()-1,nums.size(),dp);
    // }
};