class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)
            sum +=i;
            // cout<<sum<<endl;
        int ans=-1;
        int t=sum;
        int i=0;
        for(;i<nums.size();i++)
        {
            cout<<t<<endl;

            if(2*(t-nums[i])==(sum-nums[i])){
                ans=i;
                break;
            }
            else
                t -= nums[i];
        }
        return ans;
    }
};