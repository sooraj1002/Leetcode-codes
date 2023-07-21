class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<pair<int,int>> adj[V];
        for(auto flight:flights){
            int s=flight[0];
            int d=flight[1];
            int price=flight[2];

            adj[s].push_back({d,price});
        }
        
        vector<int> dist(V,INT_MAX);
        dist[src]=0;

        queue<pair<int,pair<int,int>>> q;

        //{steps,{node,cost}}
        q.push({0,{src,0}});

        while(!q.empty()){
            auto t=q.front();
            int stops=t.first;
            int node=t.second.first;
            int cost=t.second.second;
            q.pop();

            if(stops>k){
                continue;
            }

            for(auto it:adj[node]){
                int adjNode=it.first;
                int price=it.second;

                if(cost+price< dist[adjNode] && stops<=k){
                    dist[adjNode]=cost+price;
                    
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dest] != INT_MAX){
            return dist[dest];
        }
        return -1;
    }
};