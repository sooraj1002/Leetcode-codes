
class DisJointSet
{
public:
    vector<int> parent, size;
    DisJointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) // belong to same component
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisJointSet ds(n*n);

        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    continue;

                for(int k=0;k<4;k++){
                    int nrow=i+delrow[k];
                    int ncol=j+delcol[k];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n){
                        if(grid[nrow][ncol]){
                            int node=i*n+j;
                            int adjNode=nrow*n + ncol;
                            if(ds.findUPar(node) != ds.findUPar(adjNode)){  
                                ds.unionBySize(node,adjNode);
                            }
                        }
                    }
                }

            }
        }
        int ans=1;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)
                    continue;
                int area=1;
                set<int> st;
                for(int i=0;i<4;i++){
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n){
                        int adjNode=nrow*n + ncol;
                        if(grid[nrow][ncol]==1){
                            st.insert(ds.findUPar(adjNode));
                        }
                    }
                }
                for(auto it:st){
                    area+=ds.size[it];
                }
                ans=max(ans,area);
            }
        }
        for(int i=0;i<n*n;i++){
            if(ds.parent[i]==i){
                ans=max(ans,ds.size[i]);
            }
        }
        return ans;
    }
};