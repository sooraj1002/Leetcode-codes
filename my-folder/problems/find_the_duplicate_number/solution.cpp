class Solution {
public:
    void cyclicsort(vector<int> &v)
    {
        for(int i=0;i<v.size();){
            // cout<<v[i]<<"  "<<i-1<<endl;
            if(v[i]!=i+1 && v[i] !=v[v[i]-1])
            swap(v[i],v[v[i]-1]);
            else
            i++;
        }
    }

    int findDuplicate(vector<int>& nums) {
    vector<int> ans;
    cyclicsort(nums);

    return nums[nums.size()-1];
    }
};