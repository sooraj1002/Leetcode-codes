class Solution {
public:
    int rec(int i,int j,int m,int n,vector<vector<int>>&dp){

        if(i==0 && j==0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int left=0,top=0;
        if(i!=0){
            top=rec(i-1,j,m,n,dp);
        }
        if(j !=0 )
            left=rec(i,j-1,m,n,dp); 
        return dp[i][j]=top+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return rec(m-1,n-1,m,n,dp);
    }
};