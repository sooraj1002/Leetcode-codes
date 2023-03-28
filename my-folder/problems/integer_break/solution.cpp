class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n<=1)
            return 0;
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        if(n==4)
            return 4;
        if(dp[n] != -1) return dp[n];
        int maxi=-1e9;
        for(int i=3;i<=n;i++)
        {
            int half= i*(n-i);
            int prev=0;
            if(n-i>=0)
            prev= i*solve(n-i,dp);
            maxi=max(maxi,max(half,prev));
        }
        return dp[n]=maxi;
    }
    int integerBreak(int n){
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
    
    // int integerBreak(int n) {
    //     vector<int> dp(n+1,-1e8);
    //     dp[0]=0;
    //     dp[1]=0;
    //     dp[2]=1;
    //     for(int i=3;i<=n;i++){
    //         for(int j=0;j<i;j++){
    //             dp[i]=max(dp[i],max(dp[i-j]*j,j*(i-j)));      
    //             // direct breakdown of given number into 2 parts. check prev dp and multiply or just direct check bby breaking into 2 numbers
    //         }
    //     } 
    //     return dp[n];
    // }
};