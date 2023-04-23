class Solution {
public:

    // ITERATIVE SOLUTION
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,0);
        for(int index=arr.size()-1;index>=0;index--){
            int sum=0;
            int maxi=arr[index];
            int ans=0;
            for(int i=index;i<index+k;i++){
                if(i<arr.size()){
                    maxi=max(maxi,arr[i]);
                    sum=(i-index+1)*maxi+dp[i+1];
                    ans=max(ans,sum);
                }
            }
            dp[index]=ans;
        }
        return dp[0];
    }


    // RECURSIVE SOLUTION
    // int solve(vector<int> &arr,int k,int index,vector<int> &dp){
    //     if(index>=arr.size())
    //         return 0;
    //     if(dp[index] != -1)return dp[index];
    //     int sum=0;
    //     int maxi=arr[index];
    //     int ans=0;
    //     for(int i=index;i<index+k;i++){
    //         if(i<arr.size()){
    //             maxi=max(maxi,arr[i]);
    //             sum=(i-index+1)*maxi+solve(arr,k,i+1,dp);
    //             ans=max(ans,sum);
    //         }
    //     }
    //     return dp[index]=ans;
    // }
    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     vector<int> dp(arr.size()+1,-1);
    //     return solve(arr,k,0,dp);
    // }
};