class Solution {
public:
    int solve(int n,vector<int>&dp){
        // if(n<=2)
        //     return n;
        // if(dp[n] != -1) 
        //     return dp[n];
        // return dp[n]=dp[n-1]+dp[n-2];
        if(n<=1)return dp[n]= 1;
        if(dp[n]!=-1)return dp[n];
        int one=solve(n-1,dp);
        int two=0;
        if(n>1)two=solve(n-2,dp);
        return dp[n]= one+two;

    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        solve(n,dp);
        return dp[n];
        // return solve(n);
    }
};