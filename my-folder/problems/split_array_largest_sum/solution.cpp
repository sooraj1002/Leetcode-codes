class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int min=nums[0];
        int max=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            max  += nums[i];
            if(nums[i]>min)
            min=nums[i];
        }
        int start=min;
        int end=max;
        while(start<end)
        {
            int mid=start+(end-start)/2;
            int sum=0;
            int pieces=1;
            for(int i:nums)
            {
                if(sum+i>mid)
                {
                    sum=i;
                    pieces++;
                }
                else
                sum += i;
            }
            if(pieces>k)
            start=mid+1;
            else
            end=mid;
            
        }
        return end;
    }
};