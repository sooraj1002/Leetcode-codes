#define ll long long

class Solution {
public:
    int mod=1e9+7;
    int countPaths(int V, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[V];
        for(auto road:roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        //{time,node}
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
        
        vector<ll> dist(V,LLONG_MAX),ways(V,0);

        dist[0]=0;
        ways[0]=1;

        pq.push({0,0});

        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();

            ll distance=t.first;
            int node=t.second;
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgeW=it.second;
                //first arrival of distance
                if(distance+edgeW <dist[adjNode]){
                    dist[adjNode]=distance+edgeW;
                    pq.push({dist[adjNode],adjNode});

                    ways[adjNode] = ways[node] % mod;
                }
                else if(distance+edgeW==dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[V-1] %mod;
    }
};