class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n1 = s1.length();

        string s2;
        for(int i=n1-1;i>=0;i--)
        s2.push_back(s1[i]);

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
        return dp[n1][n2];
    }
};