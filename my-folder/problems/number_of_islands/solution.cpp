class Solution {
public:
    void solve(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j,int m,int n){
        vis[i][j]=1;

        if(i<m-1 && grid[i+1][j]=='1'&& !vis[i+1][j])
            solve(grid,vis,i+1,j,m,n);
        if(j<n-1 && grid[i][j+1]=='1'&& !vis[i][j+1])
            solve(grid,vis,i,j+1,m,n);
        if(i>0 && grid[i-1][j]=='1'&& !vis[i-1][j])
            solve(grid,vis,i-1,j,m,n);
        if(j>0 && grid[i][j-1]=='1'&& !vis[i][j-1])
            solve(grid,vis,i,j-1,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j] != 1){
                    count++;
                    solve(grid,vis,i,j,m,n);
                }
            }
        }
        return count;
    }
};