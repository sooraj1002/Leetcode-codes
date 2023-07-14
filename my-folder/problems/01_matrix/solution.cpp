class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0 ){
                    q.push({0,{i,j}});
                    ans[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }

        vector<int> delrow={0,1,-1,0};
        vector<int> delcol={1,0,0,-1};

        while(!q.empty()){
            auto t=q.front();
            int dist=t.first;
            int row=t.second.first;
            int col=t.second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n){
                    if(mat[nrow][ncol]==1 && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        ans[nrow][ncol]=1+dist;
                        q.push({dist+1,{nrow,ncol}});
                    }
                }
            }
        }
        return ans;
    }
};