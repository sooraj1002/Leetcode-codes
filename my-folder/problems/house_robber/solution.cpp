class Solution {
public:
    // int solve(vector<int> &nums,int n,vector<int> &dp){
    //     if(n==0)
    //         return dp[n]=nums[0];
    //     if(n<0)
    //         return 0;
    //     if(dp[n] != -1) return dp[n];
    //     int one=solve(nums,n-1,dp);
    //     int two=solve(nums,n-2,dp)+nums[n];
    //     return dp[n]=max(one,two);
    // }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> dp(n,-1);
    //     return solve(nums,n-1,dp);
    // }

    int rob(vector<int>& nums){
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1)
                take+=prev2;
            int not_take=prev;
            int curr=max(take,not_take);

            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};