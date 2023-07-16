class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int V=graph.size();
        vector<vector<int>> temp(V);
        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
                temp[it].push_back(i);
            }
        }
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto k:temp[i]){
                indegree[k]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto i:temp[node]){
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }


    //BFS SOLUTION
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     int n = graph.size();
    //     vector<int> vis(n, 0);
    //     stack<int> st;
    //     for (int i = 0; i < n; i++) {
    //         if (!vis[i]) {
    //             dfs(i, vis, st, graph);
    //         }
    //     }

    //     vector<int> ans;
    //     while (!st.empty()) {
    //         ans.insert(ans.begin(), st.top());
    //         st.pop();
    //     }
    //     return ans;
    // }

    //DFS SOLUTION
    // bool dfs(vector<vector<int>> &graph,vector<int> &vis,vector<int> &path_vis,int src,
    //         vector<int> &ans,vector<int> &check){
    //     vis[src]=1;
    //     path_vis[src]=1;
    //     for(auto i:graph[src]){
    //         if(!vis[i]){
    //             if(dfs(graph,vis,path_vis,i,ans,check))
    //                return true;                      
    //         }
    //         else if(path_vis[i]){
    //             return true;   
    //         }
    //     }
    //     check[src]=1;
    //     path_vis[src]=0;
    //     return false;
    // }
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     vector<int> vis(graph.size(),0);
    //     vector<int> path_vis(graph.size(),0);
    //     vector<int> check(graph.size());
    //     vector<int> ans;
    //     for(int i=0;i<graph.size();i++){
    //         if(!vis[i]){
    //             dfs(graph,vis,path_vis,i,ans,check);
    //         }
    //     }
    //     for(int i=0;i<graph.size();i++){
    //         if(check[i]==1)
    //             ans.push_back(i);
    //     }
    //     return ans;
    // }
};