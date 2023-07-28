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
    int removeStones(vector<vector<int>>& stones) {
        int xmax,ymax;
        for(auto it:stones){
            xmax=max(it[0],xmax);
            ymax=max(it[1],ymax);
        }
        DisJointSet ds(xmax+ymax+1);
        unordered_map<int,int> mp;
        for(auto it:stones){
            int row=it[0];
            int col=it[1]+xmax+1;
            ds.unionBySize(row,col);
            mp[row]=1;
            mp[col]=1;
        }

        int ans=stones.size();
        for(auto it:mp){
            if(ds.parent[it.first] == it.first){
                ans--;
            }
        }
        return ans;
    }
};