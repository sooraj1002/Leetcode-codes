class Solution {
public:
    int n;
    bool solve(vector<int> &nums,int index,vector<int> &vis,vector<int> &dp){
        if(index<0 || index>=nums.size()){
            return false;
        }
        if(nums[index]==0){
            return true;
        }
        if(dp[index] !=-1) return dp[index];
        vis[index]=1;
        int prev=index-nums[index];
        int next=index+nums[index];
        if(next>=0 && next<n && !vis[next] && solve(nums,next,vis,dp)){
            return dp[index]=true;
        }
        if(prev>=0 && prev<n &&  !vis[prev] && solve(nums,prev,vis,dp)){
            return dp[index]=true;
        }
        return dp[index]=false;
    }
    bool canReach(vector<int>& nums, int start) {
        n=nums.size();
        vector<int> vis(n,0),dp(n,-1);
        return solve(nums,start,vis,dp);
    }
};