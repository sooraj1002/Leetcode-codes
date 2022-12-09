class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int index=-1;
        int mid;
        while(start<end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                index=mid;
                break;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        cout<<nums[start]<<endl;
        cout<<start;
        if(index==-1)
        {
            if(nums[start]>=target)
            index=start;
            else
            index=start+1;   
        }
        return index;
    }
};