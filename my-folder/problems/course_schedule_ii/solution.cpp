class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        int V=numCourses;
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        for(int i=0;i<prereq.size();i++){
            int child=prereq[i][0];
            int parent=prereq[i][1];
            indegree[child]++;
            adj[parent].push_back(child);
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
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }
        vector<int> t;
        return topo.size()==V ? topo : t ;
    }
};