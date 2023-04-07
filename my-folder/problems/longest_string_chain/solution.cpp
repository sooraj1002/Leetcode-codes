class Solution {
public:

    static bool cmp(string &s1,string &s2){
        return s1.size()<s2.size();
    }

    static bool check(string &s1,string &s2){
        if(s1.size() != s2.size()+1) return false;

        int first=0;
        int second=0;
        while(first<s1.size()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        return first==s1.size() && second==s2.size();
    }

        int longestStrChain(vector<string>& words) {
            sort(words.begin(),words.end(),cmp);
            int n=words.size();
            vector<int> dp(n,1);
            int maxi=1;       
            for(int i=1;i<n;i++){
                for(int prev=0;prev<i;prev++){
                    if(check(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                        dp[i]=1+dp[prev];
                    }
                }
                if(dp[i]>maxi){
                    maxi=dp[i];
                }
            }
            return maxi;
        }

    // WRONG METHOD DK WHY... failed TC- ["a","b","ba","abc","abd","bdca"]
    // static bool cmp(string &s1,string &s2){
    //     return s1.size()<s2.size();
    // }

    // int lcs(string &s1,string &s2){
    //     int n1 = s1.length();
    //     int n2 = s2.length();
    //     vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    //     for (int ind1 = 1; ind1 <= n1; ind1++)
    //     {
    //         for (int ind2 = 1; ind2 <= n2; ind2++)
    //         {

    //             if (s1[ind1 - 1] == s2[ind2 - 1])
    //             { // shifted to right, so we check for index-1
    //                 dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
    //             }
    //             else
    //                 dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    //         }
    //     }
    //     return dp[n1][n2];
    // }

    // int longestStrChain(vector<string>& words) {
    //     sort(words.begin(),words.end(),cmp);
    //     for(auto i:words)
    //         cout<<i<<" ";
    //     int n=words.size();
    //     vector<int> dp(n,1);
    //     int maxi=1;       
    //     for(int i=1;i<n;i++){
    //         for(int prev=0;prev<i;prev++){
    //             int l=lcs(words[i],words[prev]);
    //             if(words[prev].size()-l==0 && 1+dp[prev]>dp[i]){
    //                 dp[i]=1+dp[prev];
    //             }
    //         }
    //         if(dp[i]>maxi){
    //             maxi=dp[i];
    //         }
    //     }
    //     return maxi;
    // }
};