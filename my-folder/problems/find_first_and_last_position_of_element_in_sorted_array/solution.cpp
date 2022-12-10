class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int index=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int right=-1;
        if(index != nums.size() &&  nums[index]==target)
        {
            right=index;
        }
        index= upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        int left=-1;
        if(index>=0 &&  nums[index]==target)
        {
            left=index;
        }
        if(right != -1)
        {
            return {right,left};
        }
        return {-1,-1};
    }
};