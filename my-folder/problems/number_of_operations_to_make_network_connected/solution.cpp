class DisJointSet{
public:
    vector<int> rank, parent, size;
    int count;  //gives number of extra wires
    DisJointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        count=0;
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) // belong to same component
            return;

        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v){ // belong to same component
            count++;
            return;
        }
        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int V, vector<vector<int>>& connections) {
        DisJointSet ds(V);
        for(auto connection:connections){
            int u=connection[0];
            int v=connection[1];
            ds.unionBySize(u,v);
        }
        int compo=0;
        for(int i=0;i<V;i++){
            // cout<<ds.parent[i]<<"  "<<i<<endl;
            if(ds.parent[i]==i){
                compo++;
            }
        }
        int avail=ds.count;
        if(compo-avail-1>0){
            return -1;
        }
        return compo-1;
    }
};