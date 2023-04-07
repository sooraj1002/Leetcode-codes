class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1),hash(n);
        int maxi=1,last=0;       
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int> list;
        list.push_back(nums[last]);
        
        while(hash[last] != last){
            last=hash[last];
            list.push_back(nums[last]);
        }
        reverse(list.begin(),list.end());
        return list;
    }
    
};