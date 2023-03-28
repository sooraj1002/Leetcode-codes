class Solution {
public:
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> ans;
    //     for(int num=0;num< (1<<n);num++){
    //         vector<int> temp;
    //         for(int i=0;i<n;i++){
    //             if(num & (1<<i))
    //                 temp.push_back(nums[i]);
    //         }
    //         ans.push_back(temp);
    //     }
    //     return ans;
    // }
    void solve(vector<int> &nums,int count,vector<int> temp,vector<vector<int>> &ans){
        if(count==nums.size()){
            ans.push_back(temp);
            return;
        }
        solve(nums,count+1,temp,ans);
        temp.push_back(nums[count]);
        solve(nums,count+1,temp,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;
        solve(nums,0,{},ans);
        return ans;
    }
};