class Solution {
public:
    //ITERATIVE SOLUTION
    int minCost(int n, vector<int>& cuts){
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),0));

        for(int i=cuts.size()-2;i>0;i--){
            for(int j=i;j<cuts.size()-1;j++){
                int mini=1e8;
                for(int index=i;index<=j;index++){
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][index-1]+dp[index+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;  
            }
        }
        return dp[1][cuts.size()-2];
    }
    //RECURSIVE SOLUTION
    // int solve(vector<int> &cuts,int i,int j,vector<vector<int>> &dp){
    //     if(i>j)
    //         return 0;
    //     if(dp[i][j] != -1)return dp[i][j];
    //     int mini=1e8;
    //     for(int index=i;index<=j;index++){
    //         int cost=cuts[j+1]-cuts[i-1]+solve(cuts,i,index-1,dp)+solve(cuts,index+1,j,dp);
    //         mini=min(mini,cost);
    //     }
    //     return dp[i][j]=mini;
    // }
    // int minCost(int n, vector<int>& cuts) {
    //     cuts.push_back(0);
    //     cuts.push_back(n);
    //     sort(cuts.begin(),cuts.end());
    //     vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1));
    //     return solve(cuts,1,cuts.size()-2,dp);
    // }
};