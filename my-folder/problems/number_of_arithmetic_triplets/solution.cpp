class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size(),count=0,flag=0;
        for(int i=0;i<=n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                if(nums[i]+diff ==nums[j])
                {
                    for(int k=j+1;k<n;k++)
                    {
                        if(nums[k]== nums[j]+diff)
                        {
                            count++;
                            // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                        }
                    }
                }
            }
        }
        return count;
        
    }
};