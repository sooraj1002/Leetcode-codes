class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<bool> a(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(a[nums[i]]==false)
            {
                a[nums[i]]=true;
            }
            else
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};