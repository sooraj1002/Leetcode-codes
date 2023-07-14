class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        for(int j=0;j<n;j++){
            if(grid[0][j]=='O'){
                q.push({0,j});
                vis[0][j]=1;
            }
            if(grid[m-1][j]=='O'){
                q.push({m-1,j});
                vis[m-1][j]=1;
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]=='O' && !vis[i][0]){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(grid[i][n-1]=='O' && !vis[i][n-1]){
                q.push({i,n-1});
                vis[i][n-1]=1;
            }
        }
        vector<int> delrow={0,1,-1,0};
        vector<int> delcol={1,0,0,-1};
        while(!q.empty()){
            auto t=q.front();
            int row=t.first;
            int col=t.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n){
                        if(grid[nrow][ncol]=='O' && !vis[nrow][ncol]){
                            vis[nrow][ncol]=1;
                            q.push({nrow,ncol});
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='O' && !vis[i][j])
                    grid[i][j]='X';
            }
        }

    }
};