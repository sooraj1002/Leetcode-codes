class Solution {
public:
    //solve(index) will tell us how  many ways to reach index from 0
    int solve(vector<int> &nums,int index,vector<int> &dp){
        if(index>=nums.size()-1)
            return 0;
        if(dp[index] != -1) return dp[index];
        // cout<<"index "<<index<<endl;
        int mini=1e8;
        for(int i=1;i<=nums[index];i++){
                mini=min(mini,1+solve(nums,index+i,dp));
                // cout<<"index+i "<<index+i<<endl;
        }
        return dp[index]=mini;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};