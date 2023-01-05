class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        auto it=m.rbegin();
        while(k>-1)
        {
            // cout<<"ele  "<<it->first<<endl;
            k=k-it->second;
            // cout<<"number of times in arr  "<<it->second<<endl;
            // cout<<"value of k  "<<k<<endl;
            if(k<=0)
            return it->first;
            it++;
        }
        return it->first;
    }
};