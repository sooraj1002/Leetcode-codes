class Solution {
public:
    int bfs(vector<vector<int>> &grid,vector<vector<int>> &vis,int m,int n,queue<pair<int,int>> &q){
        int depth=0;

        while(!q.empty()){
            int temp=q.size();
            // cout<<"temp size of queue "<<temp<<endl;
            for(int size=0;size<temp;size++){
                auto t=q.front();
                int row=t.first;
                int col=t.second;
                q.pop();
                vis[row][col]=1;
                grid[row][col]=2;
                // cout<<row<<"  "<<col<<endl;

                if(row>0 && grid[row-1][col]==1 && !vis[row-1][col]){
                    vis[row-1][col]=1;
                    q.push({row-1,col});
                    // cout<<"r-1,c "<<row-1<<" "<<col<<endl;
                }

                if(col>0 && grid[row][col-1]==1 && !vis[row][col-1]){
                    vis[row][col-1]=1;
                    q.push({row,col-1});
                    // cout<<"r,c-1 "<<row<<"  "<<col-1<<endl;
                }

                if(row<m-1 && grid[row+1][col]==1 && !vis[row+1][col]){
                    vis[row+1][col]=1;
                    pair<int,int> temp=make_pair(row+1,col);
                    q.push(temp);
                    // cout<<"r+1,c "<<temp.first<<"  "<<temp.second<<endl;
                }

                if(col<n-1 && grid[row][col+1]==1 && !vis[row][col+1]){
                    vis[row][col+1]=1;
                    q.push({row,col+1});
                    // cout<<"r,c+1 "<<row<<"  "<<col+1<<endl;
                }
            }
            depth++;
        }
        return depth;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        bool f=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2 && !vis[i][j]){
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                    f=1;
            }
        }
        int ans=bfs(grid,vis,m,n,q);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    return -1;
            }
            // cout<<endl;
        }
        if(f==0)
            return 0;
        return ans-1;
    }
};