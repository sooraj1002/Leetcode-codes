class Solution {
public:
    int solve(vector<int> &num,int target,int index,vector<vector<int>> &dp){
        if(index==0){
            if(target==0 && num[0]==0)return 2;
            if(target==0 || num[0]==target) return 1;
            return 0;
        }
        if(dp[index][target] != -1)return dp[index][target];
        int not_take=solve(num,target,index-1,dp);
        int take=0;

        if(num[index]<=target)
            take=solve(num,target-num[index],index-1,dp);

        return dp[index][target]=(take+not_take);
    }

    int findTargetSumWays(vector<int>& nums, int d) {
        int sum=0;
        for(auto i:nums){
            sum +=i;
        }
        int target=(sum-d)/2;
        if(sum<d || (sum-d)%2 ==1)
            return 0;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return solve(nums,target,nums.size()-1,dp);
    }
};