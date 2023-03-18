class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n,vector<vector<int>> &dp){
        if(obstacleGrid[i][j]==1)
            return 0;
        if(i==0 && j==0){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up=0,back=0;
        if(i != 0)
            up=solve(obstacleGrid,i-1,j,m,n,dp);
        if(j != 0)
            back=solve(obstacleGrid,i,j-1,m,n,dp);
        return dp[i][j]=up+back;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         dp
        //     }
        // }





        return solve(obstacleGrid,m-1,n-1,m,n,dp);
    }
};