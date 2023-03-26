class Solution {
public:
    int solve(vector<vector<int>> &grid,int i,int j1,int j2,int max_rows,int max_cols,vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=max_cols || j2>= max_cols)
            return -1e8;
        
        if(i==max_rows-1){
            if(j1==j2)
                return grid[i][j1];
            else
               return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi=0;
        for(int dr1=-1;dr1<2;dr1++){
            for(int dr2=-1;dr2<2;dr2++){
                if(j1==j2)
                    maxi=max(maxi,grid[i][j1]+solve(grid,i+1,j1+dr1,j2+dr2,max_rows,max_cols,dp));
                else
                    maxi=max(maxi,grid[i][j1]+grid[i][j2]+solve(grid,i+1,j1+dr1,j2+dr2,max_rows,max_cols,dp));
            }
        }
        return dp[i][j1][j2]=maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        auto temp=grid;
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        // return solve(grid,0,0,n-1,m,n,dp);

        //TABULATION SOLUTION//
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,0 )));
        for(int j1=n-1;j1>=0;j1--)
        {
            for(int j2=n-1;j2>=0;j2--){
                if(j1==j2)
                    dp[m-1][j1][j2]=grid[m-1][j1];
                else
                    dp[m-1][j1][j2]=grid[m-1][j1]+grid[m-1][j2];
            }
        }

        for(int i=m-2;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){

                    int maxi= -1e8;
                    for(int dr1=-1;dr1<2;dr1++){
                        for(int dr2=-1;dr2<2;dr2++){
                            int val=0;
                            if(j1==j2)
                                val =grid[i][j1];
                            else
                                val= grid[i][j1]+grid[i][j2];
                            if(j1+dr1>=0 && j1+dr1 <n && j2+dr2 >=0 && j2+dr2<n)
                                val+= dp[i+1][j1+dr1][j2+dr2];
                            else
                                val+= -1e8;
                            maxi=max(maxi,val);   
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        
        return dp[0][0][n-1];

    }

};