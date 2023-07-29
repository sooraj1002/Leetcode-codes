class Solution {
public:
    int binsrc(vector<int> &nums,int start,int end,int target,bool &f){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        f=1;
        return end;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int tar=target-nums[l];
            // have to find target in (l+1,r)
            bool f=0;
            int t=binsrc(nums,l+1,r,tar,f);
            if(f){
                l++;
                r=t;
            }
            else{
                return {l+1,t+1};
            }
        }
        return{};
    }
};