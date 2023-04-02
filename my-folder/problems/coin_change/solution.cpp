class Solution {
public:
    //solve(index,target) tells us the minimum number of coins to active target using the coins till  index
    int solve(int index,int target,vector<int> &coins,vector<vector<int>>&dp){
        // if(target==0)
        //     return 0;
        if(index==0){
            if(target%coins[index]==0)
                return target/coins[index];
            else
                return 1e8;
        }
        if(dp[index][target] != -1) return dp[index][target];
        int not_take=solve(index-1,target,coins,dp);
        int take=1e8;
        if(coins[index]<=target)
            take= 1+ solve(index,target-coins[index],coins,dp);    //dont reduce index in this case because we might want to take more coins
        
        return dp[index][target]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(coins.size()-1,amount,coins,dp);
        if(ans==1e8)
            return -1;
        return ans;
    }


    // TABULATION SOLUTION

    // int coinChange(vector<int>& coins, int amount){
    //     vector<int> dp(amount+1,1e8);
    //     dp[0]=0;
    //     for(int i=1;i<amount+1;i++){
    //         for(auto j:coins){
    //             if(i-j >=0)
    //             dp[i]=min(dp[i],1+dp[i-j]);
    //         }
    //     }
    //     if(dp[amount]==1e8)
    //         return -1;
    //     return dp[amount];
    // }
};