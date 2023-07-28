#define ll long long 
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll maxi=0;
        ll sum=0;
        map<int,int> mp;
        int count=0;       //stores number of repeated elements in the window
        for(int i=0;i<k;i++){
            sum+=nums[i];
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]]++;
            }
            else{
                mp[nums[i]]++;
                count++;
            }
        }
        // cout<<count<<"  "<<sum<<endl;
        if(count==0)
            maxi=max(maxi,sum);
        
        // for(auto it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        int out=0,in=0;
        for(int i=k;i<nums.size();i++){
            out=nums[i-k];
            in=nums[i];

            if(mp[out]>1){
                count--;
            }
            mp[out]--;
            
            mp[in]++;
            if(mp[in]>1){
                count++;
            }
            sum = sum-out +in;
            // cout<<count<<"  "<<sum<<endl;
            if(count==0){
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};