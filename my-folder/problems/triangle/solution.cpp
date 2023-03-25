class Solution {
public:
    int solve(vector<vector<int>> &triangle,int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i==m)
            return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down=solve(triangle,m,n,i+1,j,dp);
        int shift=solve(triangle,m,n,i+1,j+1,dp);
        return dp[i][j]=min(down,shift)+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(triangle,m-1,n-1,0,0,dp);
        // for(int j=0;j<)
    }
};