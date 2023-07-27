class DisJointSet
{
public:
    vector<int> rank, parent, size;
    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
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

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) // belong to same component
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
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
    int findCircleNum(vector<vector<int>>& isConnected){
        int V=isConnected.size();
        DisJointSet ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]){
                    ds.unionBySize(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i)
                count++;
        }
        return count;
    }
    // void dfs(int node,vector<vector<int>> &isConnected,vector<int> &vis,int n){
    //     vis[node]=1;
    //     for(int i=0;i<n;i++){
    //         if(isConnected[node][i]==1 && !vis[i]){
    //             dfs(i,isConnected,vis,n);
    //         }
    //     }
    // }
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int n=isConnected.size();
    //     vector<int> vis(n,0);
    //     int count=0;
    //     for(int i=0;i<n;i++){
    //         if(!vis[i]){
    //             // cout<<i<<endl;
    //             count++;
    //             dfs(i,isConnected,vis,n);
    //         }
    //     }
    //     return count;
    // }
};