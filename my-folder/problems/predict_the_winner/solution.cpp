class Solution {
public:
    int solve(vector<int> &nums,int start,int end,int player,vector<vector<vector<int>>> &dp){
        if(start>end){
            return 0;
        }
        
        if(dp[start][end][player] != -1)return dp[start][end][player];

        if(player==0){
            int first=nums[start]+solve(nums,start+1,end,1,dp);
            int second=nums[end]+solve(nums,start,end-1,1,dp);
            return dp[start][end][player]=max(second,first);
        }
        else{
            int first=solve(nums,start+1,end,0,dp);
            int second=solve(nums,start,end-1,0,dp);
            return dp[start][end][player]=min(first,second);
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(2,-1)));
        int t=solve(nums,0,nums.size()-1,0,dp);
        int s=0;
        for(auto i:nums)
            s+=i;
        
        return t>=s-t;
    }
};