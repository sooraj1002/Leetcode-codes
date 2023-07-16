class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
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
        vector<bool> topo(V,0);
        while(!q.empty()){
            int node=q.front();
            topo[node]=1;
            q.pop();
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }
        for(auto i:topo){
            if(!i)
                return false;
        }
        return true;
    }
};