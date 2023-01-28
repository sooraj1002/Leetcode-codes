class Solution {
public:

    void cyclicsort(vector<int> &v){
        for(int i=0;i<v.size();i++){
            if(v[i]==v.size())
            continue;
            else
            {
                while(v[i]<v.size() && v[i]!=i)
                swap(v[i],v[v[i]]);
            }
        }
    }

    int missingNumber(vector<int>& nums) {
        cyclicsort(nums);
        for(auto i:nums)
        cout<<i<<"   ";
        int i=0;
        for(;i<nums.size();i++)
        {
            if(i != nums [i])
                break;
        }
        return i;
    }
};