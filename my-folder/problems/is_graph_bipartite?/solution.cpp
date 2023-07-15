class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<int> &vis,int src,int color){
        vis[src]=color;
        bool ans=true;
        for(auto i:graph[src]){
            if( vis[i]==-1){
                vis[i]=!vis[src];
                ans= ans && dfs(graph,vis,i,!color);
            }
            else if(i != src && vis[i]==color ){
                return false;
            }
        }
        return ans;
    }
    //DFS solution
    bool isBipartite(vector<vector<int>>& graph){
        vector<int> vis(graph.size(),-1);
        bool ans=true;
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
                if (!dfs(graph,vis,i,0))
                    return false;
            }
        }
        return true;
    }
    //BFS SOLUTION
    // bool bfs(vector<vector<int>> &graph,vector<int> vis,int src){
    //     vis[src]=1;
    //     queue<pair<int,int>> q;
    //     q.push({src,vis[src]});
    //     while(!q.empty()){
    //         auto t=q.front();
    //         int node=t.first;
    //         int color=t.second;
    //         q.pop();
    //         for(auto i:graph[node]){
    //             // cout<<i<<"  "<<vis[i]<<" color "<<color<<endl;
    //             if(vis[i]==0){
    //                 vis[i]= 1==color? 2 :1;
    //                 q.push({i,vis[i]});
    //             }
    //             else if(vis[i]==color){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    // bool isBipartite(vector<vector<int>>& graph) {
    //     vector<int> vis(graph.size(),0); 
    //     bool ans=true;  
    //     for(int i=0;i<graph.size();i++){
    //         if(vis[i]==0){
    //             ans=ans && bfs(graph,vis,i);
    //         }
    //     }
    //     return ans;
    // }
};