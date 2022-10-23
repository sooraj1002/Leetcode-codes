class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i+=2)
        {
            int t1=nums[i];
            int t2=nums[i+1];
            for(int i=0;i<t1;i++)
                ans.push_back(t2);
        }
        return ans;
    }
};