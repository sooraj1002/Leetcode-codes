class Solution {
public:
    int pivot(vector<int>& nums)
    {
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            //make cases for the positions where mid can lie
            if(mid<end  && nums[mid]>nums[mid+1])  //pivot condition that mid=7 and mid+1=1
            return mid;
            if (mid>start && nums[mid]<nums[mid-1])   // pivot condition that mid=1 and mid-1=7
            return mid-1; 
            //now mid can only be wither of the increasing parts
            if(nums[mid]<=nums[start])
            end=mid-1;                  //all others after mid are smaller as it is alreadysorted and other cases have been taken in previous ifs
            else
            start=mid+1;
        }
        return -1;
    }
    int binsrch(vector<int>& nums,int target,int start,int end)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target<nums[mid])
            end=mid-1;
            else if(target>nums[mid])
            start=mid+1;
            else
            return mid;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int piv=pivot(nums);
        int ans;
        if(piv==-1)
        ans=binsrch(nums,target,0,nums.size()-1);
        else
        {
            ans=binsrch(nums,target,0,piv);
            if(ans==-1)
            ans=binsrch(nums,target,piv+1,nums.size()-1);
        }
        return ans;
    }
};