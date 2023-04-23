class Solution {
public:
    //ITERATIVE SOLUTION
    int maxCoins(vector<int>& nums){
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        for(int i=nums.size()-2;i>0;i--){
            for(int j=i;j<nums.size()-1;j++){

                int maxi=-1e8;
                for(int index=i;index<=j;index++){
                    int cost=nums[i-1]*nums[index]*nums[j+1]+dp[i][index-1]+dp[index+1][j];
                    maxi=max(maxi,cost);
                }
                dp[i][j]=maxi;               
            }
        }
        return dp[1][nums.size()-2];
    }
    //RECURSIVE SOLUTION
    // int solve(vector<int> &nums,int i,int j,vector<vector<int>> &dp){
    //     if(i>j)
    //         return 0;
    //     if(dp[i][j] != -1)return dp[i][j];
    //     int maxi=-1e8;
    //     for(int index=i;index<=j;index++){
    //         int cost=nums[i-1]*nums[index]*nums[j+1]+solve(nums,i,index-1,dp)+solve(nums,index+1,j,dp);
    //         maxi=max(maxi,cost);
    //     }
    //     return dp[i][j]=maxi;
    // }
    // int maxCoins(vector<int>& nums) {
    //     nums.push_back(1);
    //     nums.insert(nums.begin(),1);
    //     vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
    //     return solve(nums,1,nums.size()-2,dp);
    // }
};