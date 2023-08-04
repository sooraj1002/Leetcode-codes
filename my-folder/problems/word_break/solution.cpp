class Solution {
public:
    bool solve(string s,unordered_set<string> &st,vector<vector<int>> &dp,int left,int right){
        if(st.find(s) != st.end()){
            return true;
        }

        if(dp[left][right] != -1)return dp[left][right];
        
        int len=s.size();
        for(int i=1;i<len;i++){
            string s1=s.substr(0,i);
            string s2=s.substr(i,len-i);
            bool first=solve(s1,st,dp,left,left+i-1);
            bool second=solve(s2,st,dp,left+i,right);
            if(first && second){
                return dp[left][right]=true;
            }
        }
        return dp[left][right]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        unordered_set<string> st;
        for(auto str:wordDict){
            st.insert(str);
        }
        return solve(s,st,dp,0,n-1);
    }
};