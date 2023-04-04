class Solution {
public:
    // RECURSIVE SOLUTION
    // int solve(string &s1,string &s2,int ind1,int ind2,vector<vector<int>> &dp){
    //     if(ind2<0) return 1;
    //     if(ind1<0) return 0;

    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    //     int ans=0;
    //     if(s1[ind1]==s2[ind2]){
    //         ans+=solve(s1,s2,ind1-1,ind2,dp)+solve(s1,s2,ind1-1,ind2-1,dp);
    //     }
    //     else{
    //         ans+=solve(s1,s2,ind1-1,ind2,dp);
    //     }
    //     return dp[ind1][ind2]=ans;
    // }
    // int numDistinct(string s, string t) {
    //     vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
    //     return solve(s,t,s.size()-1,t.size()-1,dp);
    // }

    // ITERATIVE SOLUTION
    int numDistinct(string s1, string s2){
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<double>> dp(s1.size()+1,vector<double>(s2.size()+1,0));
        for(int i=0;i<=n1;i++)
            dp[i][0]=1;

        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2=1;ind2<=n2;ind2++){
                if(s1[ind1-1]==s2[ind2-1])
                    dp[ind1][ind2]=dp[ind1-1][ind2]+dp[ind1-1][ind2-1];
                else
                    dp[ind1][ind2]=dp[ind1-1][ind2];
            }
        }
        return (int)dp[n1][n2];
    }
};