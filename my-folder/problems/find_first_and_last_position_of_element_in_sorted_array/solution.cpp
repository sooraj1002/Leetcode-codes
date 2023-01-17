class Solution {
public:
    int search(vector<int>& nums,int target,bool findstart)
    {
        int start=0;
        int end=nums.size()-1;
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target<nums[mid])
            end=mid-1;
            else if(target>nums[mid])
            start=mid+1;
            else
            {
                ans=mid;
                if(findstart)
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start= search(nums,target,true);
        // int end=0;
        int end= search(nums,target,false);
        vector<int> ans ={start,end};
        return ans;
    }
};