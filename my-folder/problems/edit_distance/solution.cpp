class Solution {
public:
    int solve(string &s1,string &s2,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1<0)
            return ind2+1;
        if(ind2<0)
            return ind1+1;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(s1[ind1]==s2[ind2])return solve(s1,s2,ind1-1,ind2-1,dp);

        int replace=solve(s1,s2,ind1-1,ind2-1,dp);
        int remove=solve(s1,s2,ind1-1,ind2,dp);
        int insert=solve(s1,s2,ind1,ind2-1,dp);
        
        return dp[ind1][ind2]=min(replace,min(remove,insert))+1;
    }
    int minDistance(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return solve(s1,s2,s1.size()-1,s2.size()-1,dp);
    }
};