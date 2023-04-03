class Solution {
public:

    int longestCommonSubsequence(string s1, string s2){
        int n1=s1.length();
        int n2=s2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2=1;ind2<=n2;ind2++){

                if(s1[ind1-1]==s2[ind2-1]){                   //shifted to right, so we check for index-1
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                }
                else
                    dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[n1][n2];
    }

    //RECURSIVE SOLUTION
    // int solve(string &s1,string &s2,int ind1,int ind2,vector<vector<int>> &dp){
    //     if(ind1<0 || ind2<0)
    //         return 0;
    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    //     if(s1[ind1]==s2[ind2])
    //         return dp[ind1][ind2]=1+solve(s1,s2,ind1-1,ind2-1,dp);
        
    //     return dp[ind1][ind2]=max(solve(s1,s2,ind1-1,ind2,dp),solve(s1,s2,ind1,ind2-1,dp));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n1=text1.length();
    //     int n2=text2.length();
    //     vector<vector<int>> dp(n1,vector<int>(n2,-1));
    //     return solve(text1,text2,n1-1,n2-1,dp);
    // }
};