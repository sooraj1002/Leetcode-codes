class Solution {
public:
    int solve(vector<vector<int>>& grid,int m,int n,vector<vector<int>> &dp){
        if(m==0 && n==0)
            return grid[m][n];
        if(m<0 || n<0)
            return INT_MAX;
        if(dp[m][n] != -1) return dp[m][n];
        int up=solve(grid,m-1,n,dp);
        int back=solve(grid,m,n-1,dp);
        return dp[m][n]=min(back,up)+grid[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // return solve(grid,m-1,n-1,dp);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) 
                    dp[i][j]=grid[i][j];
                else{
                    int up=grid[i][j],left=grid[i][j];
                    if(i>0) up +=dp[i-1][j];
                    else up =INT_MAX;
                    if(j>0) left +=dp[i][j-1];
                    else left = INT_MAX;
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};