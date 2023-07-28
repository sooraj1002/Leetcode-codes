class Solution {
public:
    int timer=1;
    void dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &time,
                vector<int> &lowest,vector<int> &vis,vector<vector<int>> &bridges){
        vis[node]=1;
        time[node]=timer;
        lowest[node]=timer;
        timer++;

        for(auto it:adj[node]){
            if(it==parent){
                continue;
            }
            if(vis[it]==0){
                dfs(it,node,adj,time,lowest,vis,bridges);
                //we have come back from traversal
                lowest[node]=min(lowest[it],lowest[node]);

                //check if it is a bridge
                if(lowest[it] > time[node]){  //cannot reach it from node other way
                    bridges.push_back({it,node});
                }
            }
            else{ //coming back after visiting, so it is a component that is confirmed
                lowest[node]=min(lowest[node],lowest[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> time(n);
        vector<int> lowest(n);

        vector<vector<int>> bridges;

        dfs(0,-1,adj,time,lowest,vis,bridges);

        return bridges;
    }
};