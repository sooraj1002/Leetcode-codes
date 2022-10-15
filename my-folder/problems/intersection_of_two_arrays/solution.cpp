class Solution {
public:
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(),l2=nums2.size();
        vector<int> v;
        for(int i=0;i<l1;i++)
        {
            for(int j=0;j<l2;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    cout<<"l"<<endl;
                    v.push_back(nums1[i]);
                }
            }
        }
        vector<int> ans;
        if(v.size()>0)
        {sort(v.begin(),v.end());
        ans.push_back(v[0]);
        int k=0;
        for(int i=1;i<v.size();i++)
        {
            if(ans[k] != v[i])
            {
                ans.push_back(v[i]);
                k++;
            }
        }}
        return ans;
    }
};