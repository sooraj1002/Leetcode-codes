class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int n=nums.size();
        if(nums[l]<=nums[r])
        {
            return nums[0];
        }
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(mid-1>=0 &&nums[mid]<nums[mid-1])
            {
                return nums[mid];
            }
            else if(mid+1<n && nums[mid]>nums[mid+1])
            {
                return nums[mid+1];
            }
            else if(nums[l]<=nums[mid])
            {
                l=mid+1;
            }
            else if(nums[mid]<=nums[r])
            {
                r=mid+1;
            }
            
        }
        return nums[0];
    }
};