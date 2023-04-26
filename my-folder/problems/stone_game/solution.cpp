class Solution {
public:
    int solve(vector<int> &piles,int start,int end,int player,vector<vector<vector<int>>> &dp){
        if(start>end){
            return 0;
        }
        
        if(dp[start][end][player] != -1)return dp[start][end][player];

        if(player==0){
            int first=piles[start]+solve(piles,start+1,end,1,dp);
            int second=piles[end]+solve(piles,start,end-1,1,dp);
            return dp[start][end][player]=max(second,first);
        }
        else{
            int first=solve(piles,start+1,end,0,dp);
            int second=solve(piles,start,end-1,0,dp);
            return dp[start][end][player]=min(first,second);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int t= solve(piles,0,piles.size()-1,0,dp);
        
        int s=0;
        for(auto i:piles){
            s+=i;
        }
        return t>s-t;
    }
};