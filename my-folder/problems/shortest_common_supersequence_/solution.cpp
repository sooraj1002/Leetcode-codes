class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int ind1 = 1; ind1 <= n1; ind1++)
        {
            for (int ind2 = 1; ind2 <= n2; ind2++)
            {

                if (s1[ind1 - 1] == s2[ind2 - 1])
                { // shifted to right, so we check for index-1
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
        string ans;
        map<char,vector<int>> mp;
        while(n1>0 && n2>0){
            if(s1[n1-1]==s2[n2-1]){
                ans.push_back(s1[n1-1]);
                n1--;
                n2--;
            }
            else if(dp[n1-1][n2]>dp[n1][n2-1]){
                ans.push_back(s1[n1-1]);
                n1--;
            }
            else{
                ans.push_back(s2[n2-1]);
                n2--;
            }
        }
        while(n1 > 0){
            ans.push_back(s1[n1-1]);
            n1--;
        }
        while(n2 > 0){
            ans.push_back(s2[n2-1]);
            n2--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};