class Solution {
public:
    bool isPalindrome(string &s,int start,int end){
        while(start<end){
            if(s[start] != s[end])
                return 0;
            start++;
            end--;
        }
        return 1;
    }
    int solve(string &s,int index,vector<int> &dp){
        if(index==s.size())
            return 0;
        if(dp[index] != -1)return dp[index];
        int count=0;
        for(int j=index;j<s.size();j++){
            if(isPalindrome(s,index,j)){
                count++;
            }
        }
        count += solve(s,index+1,dp);
        return dp[index]=count;
    }
    int countSubstrings(string s) {
        vector<int> dp(s.size(),-1);
        return solve(s,0,dp);
    }
};