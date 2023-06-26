class Solution {
public:
    //kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN,sum=0;
        for(auto i:nums){
            sum+=i;
            if(sum>maxi)
                maxi=sum;
            
            if(sum<0)
                sum=0;
        }
        return maxi;
    }
};