class Solution {
public:

void dfs(vector<vector<int>> &graph,vector<vector<int>> &ans,vector<int> temp,int start,int final)
{
    temp.push_back(start);
    if(start==final)
    {
        ans.push_back(temp);
        temp.clear();
    }

    for(auto i:graph[start])
    dfs(graph,ans,temp,i,final);
}

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>> ans;
        vector<int> temp;
        int n=graph.size();
        if(n==0)
        return ans;
        dfs(graph,ans,temp,0,n-1);
        return ans;
    }
};