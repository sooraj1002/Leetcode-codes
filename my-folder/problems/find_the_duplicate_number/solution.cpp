class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<bool> t(n,false);
        int ans;
        for(int i=0;i<n;i++)
        {
            if(t[nums[i]]==false)
            t[nums[i]]=true;
            else if(t[nums[i]]==true)
            {
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};