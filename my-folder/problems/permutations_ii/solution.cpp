class Solution {
public:
    void solve(vector<int> &nums,int index,vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        set<int> st;  //stores eleements so repeated elements not swapped
        for(int i=index;i<nums.size();i++){
            if(st.find(nums[i]) != st.end())
                continue;
            st.insert(nums[i]);
            swap(nums[index],nums[i]);
            solve(nums,index+1,ans);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums){
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
    // void solve(vector<int> &nums,int index,set<vector<int>> &st){
    //     if(index==nums.size()){
    //         st.insert(nums);
    //         return;
    //     }
    //     for(int i=index;i<nums.size();i++){
    //         swap(nums[index],nums[i]);
    //         solve(nums,index+1,st);
    //         swap(nums[index],nums[i]);
    //     }
    // }
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     set<vector<int>> st;
    //     vector<vector<int>> ans;
    //     solve(nums,0,st);
    //     for(auto it:st){
    //         ans.push_back(it);
    //     }
    //     return ans;
    // }
};