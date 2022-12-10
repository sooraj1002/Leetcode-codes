class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<bool> t(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(t[nums[i]]==false)
            t[nums[i]]=true;
        }
        for(int i=1;i<=n;i++)
        {
            if(t[i]==false)
            ans.push_back(i);
        }
        return ans;
    }
};