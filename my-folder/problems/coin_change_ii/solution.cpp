class Solution {
public:
    int solve(vector<int> &coins,int target,int index,vector<vector<int>> &dp){
        if(target==0)return 1;
        if(index==0){
            if(target%coins[0]==0)
                return 1;
            return 0;
        }
        if(dp[index][target] != -1)return dp[index][target];
        int not_take=solve(coins,target,index-1,dp);
        int take=0;
        if(target>=coins[index])
            take=solve(coins,target-coins[index],index,dp);
        return dp[index][target]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        if(amount==0)return 1;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins,amount,coins.size()-1,dp);
    }
};