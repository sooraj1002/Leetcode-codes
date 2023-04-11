class Solution {
public:

    //ITERTIVE SOLUTION
    int getMoneyAmount(int n){
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        
        for(int start=n;start>=1;start--){
            for(int end=start;end<=n;end++){
                if(start==end)
                    continue;
                else{    
                    int ans=1e8;
                    for(int i=start;i<=end;i++){
                         
                        int first=dp[start][i-1];
                        int second=dp[i+1][end];
                        ans=min(ans,max(first,second)+i);
                    }
                    dp[start][end]=ans;
                }
            }
        }
        return dp[1][n];
    }


    //RECURSIVE SOLUTION
    // int solve(int start,int end,vector<vector<int>> &dp){
    //     if(start>=end)
    //         return 0;
    //     if(dp[start][end] != -1) return dp[start][end];
    //     int ans=1e8;
    //     for(int i=start;i<=end;i++){

    //         int first=solve(start,i-1,dp);
    //         int second=solve(i+1,end,dp);
    //         ans=min(ans,max(first,second)+i);
    //     }   
    //     return dp[start][end]=ans;
    // }
    // int getMoneyAmount(int n) {
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    //     return solve(1,n,dp);
    // }
};