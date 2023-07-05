class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2;
        for(auto i:nums1){
            mp1[i]++;
        }
        for(auto i:nums2){
            mp2[i]++;
        }
        vector<int> ans1,ans2;
        for(auto i:mp1){
            int num=i.first;
            if(mp2.find(num)==mp2.end())
                ans1.push_back(num);
        }
        for(auto i:mp2){
            int num=i.first;
            if(mp1.find(num)==mp1.end())
                ans2.push_back(num);
        }
        vector<vector<int>> ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};