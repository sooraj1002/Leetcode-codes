class Solution {
public:
    bool isPalindrome(int start,int end,string &s){
        while(start<end){
            if(s[start] != s[end])
                return 0;
            start++;
            end--;
        }
        return 1;
    }

    //ITERATIVE SOLUTION
    int minCut(string s){
        vector<int> dp(s.size()+1,0);
        for(int index=s.size()-1;index>=0;index--){
            int minCost=1e8;
            for(int j=index;j<s.size();j++){
                if(isPalindrome(index,j,s)){
                    int cost=1+dp[j+1];
                    minCost=min(minCost,cost);
                }
            }
            dp[index]=minCost;
        }
        return dp[0]-1;
    }
    //RECURSIVE SOLUTION
    // int solve(string &s,int index,vector<int> &dp){
    //     if(index==s.size()) return 0;
    //     if(dp[index] != -1) return dp[index];
    //     int minCost=1e8;
    //     for(int j=index;j<s.size();j++){
    //         if(isPalindrome(index,j,s)){
    //             int cost=1+solve(s,j+1,dp);
    //             minCost=min(minCost,cost);
    //         }
    //     }
    //     return dp[index]=minCost;
    // }
    // int minCut(string s) {
    //     vector<int> dp(s.size(),-1);
    //     return solve(s,0,dp)-1;    //as we are doing a partition at end
    // }
};