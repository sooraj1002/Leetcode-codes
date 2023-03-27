class Solution {
public:
    bool solve(vector<int> &nums,int target,int index,vector<vector<int>> &dp){
        if(target==0)
            return true;
        if(index==0)
            return (nums[0]==target);
        if(dp[index][target] != -1) return dp[index][target];

        bool not_take=solve(nums,target,index-1,dp);
        bool take=false;
        if(nums[index]<=target)
            take=solve(nums,target-nums[index],index-1,dp);
        
        return dp[index][target]=take|| not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)
            sum+=i;
        if(sum %2 ==1)
            return false;
        vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,-1));
        return solve(nums,sum/2,nums.size()-1,dp);
    }
};