class Solution {
public:
    int r,c;
    vector<int> delrow={0,1,-1,0};
    vector<int> delcol={1,0,0,-1};

    void bfs(int i,int j,vector<vector<int>> & heights,vector<vector<int>> &effort){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({i,j});
        while(!pq.empty()){
            auto t =pq.top();
            pq.pop();
            int row=t.first;
            int col=t.second;
            int curr_effort=effort[row][col];
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol >=0 && nrow<r && ncol<c){
                    int neffort= abs(heights[row][col]-heights[nrow][ncol]);
                    neffort=max(curr_effort,neffort);
                    if(neffort<effort[nrow][ncol]){
                        effort[nrow][ncol]=neffort;
                        pq.push({nrow,ncol});
                    }
                }
            }
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        r=rows,c=cols;
        vector<vector<int>> effort(rows,vector<int>(cols,INT_MAX));
        effort[0][0]=0;

        bfs(0,0,heights,effort);

        return effort[rows-1][cols-1];
    }
};