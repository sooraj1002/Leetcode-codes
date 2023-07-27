
class DisJointSet
{
    vector<int> rank, parent, size;

public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int V=accounts.size();

        DisJointSet ds(V);
        map<string,int> mp;

        for(int i=0;i<V;i++){
            for(int j=1;j<accounts[i].size();j++){
                string temp=accounts[i][j];
                if(mp.find(temp) == mp.end()){
                    mp[temp]=i;
                }
                else{
                    int t=mp[temp];
                    ds.unionBySize(i,t);
                }
            }
        }
        vector<string> merged[V];   
        for(auto it:mp){
            string name=it.first;
            int parent=ds.findUPar(it.second);

            merged[parent].push_back(name);
        }
        
        vector<vector<string>> ans;
        for(int i=0;i<V;i++){
            if(merged[i].size()==0)
                continue;

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        
        }
        return ans;
    }
};