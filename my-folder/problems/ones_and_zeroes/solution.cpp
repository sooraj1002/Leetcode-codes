class Solution {
public:
    //ITERATIVE SOLUTION
    int findMaxForm(vector<string>& strs, int m1, int n1){
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m1+1,vector<int>(n1+1,0)));

        for(int index=strs.size()-1;index>=0;index--){
            for(int m=m1;m>=0;m--){
                for(int n=n1;n>=0;n--){
                    int k1=m,k2=n;
                    int not_take=dp[index+1][m][n];
                    auto s=strs[index];
                    for(int c:s){
                        if(c=='0')
                            k1--;
                        else if(c=='1')
                            k2--;
                    }
                    int take=0;
                    if(k1>=0 && k2>=0)
                        take=1+dp[index+1][k1][k2];
                    dp[index][m][n]=max(take,not_take);
                }
            }
        }
        return dp[0][m1][n1];
    }
    //RECURSIVE SOLUTION
    // int solve(vector<string> &strs,int m,int n,int index,vector<vector<vector<int>>> &dp){
    //     if(index==strs.size())
    //         return 0;
    //     int m1=m,n1=n;
    //     if(dp[index][m][n] != -1)return dp[index][m][n];
    //     int not_take=solve(strs,m,n,index+1,dp);
    //     auto s=strs[index];
    //     for(int c:s){
    //         if(c=='0')
    //             m--;
    //         else if(c=='1')
    //             n--;
    //     }
    //     int take=0;
    //     if(m>=0 && n>=0)
    //         take=1+solve(strs,m,n,index+1,dp);
    //     return dp[index][m1][n1]=max(take,not_take);
    // }
    // int findMaxForm(vector<string>& strs, int m, int n) {
    //     vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
    //     return solve(strs,m,n,0,dp);
    // }
};