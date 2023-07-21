class Solution {
public:
    int size;

    void bfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dist){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({i,j});
        while(!pq.empty()){
            auto t =pq.top();
            pq.pop();
            int row=t.first;
            int col=t.second;
            int distance=dist[row][col];
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    int ndist=distance+1;
                    if(nrow>=0 && ncol >=0 && nrow<size && ncol<size 
                        && grid[nrow][ncol]==0 && ndist < dist[nrow][ncol]){
                        dist[nrow][ncol]=ndist;
                        pq.push({nrow,ncol});
                    }
                }
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        size=n;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;

        if(grid[0][0]==1){
            return -1;
        }

        bfs(0,0,grid,dist);
        return dist[n-1][n-1]==INT_MAX ? -1 : dist[n-1][n-1];
    }
};