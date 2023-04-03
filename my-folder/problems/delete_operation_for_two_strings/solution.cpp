class Solution {
public:

    int minDistance(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
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
        return n1-dp[n1][n2]+n2-dp[n1][n2];
    }    
};