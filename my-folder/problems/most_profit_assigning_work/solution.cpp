class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<int> dp(100001,0);   //so that all difficulties are done

        for(int i=0;i<difficulty.size();i++){
            dp[difficulty[i]]=max(dp[difficulty[i]],profit[i]);
        }

        for(int i=1;i<dp.size();i++){
            dp[i]=max(dp[i],dp[i-1]);
        }

        int ans=0;
        for(auto i:worker){
            ans+=dp[i];
        }
        
        return ans;
    }
};