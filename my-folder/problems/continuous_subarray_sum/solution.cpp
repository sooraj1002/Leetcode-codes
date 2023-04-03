class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        
        int prefsum=0;

        for(int i=0;i<nums.size();i++){
            prefsum+=nums[i];
            prefsum %= k;

            if(prefsum ==0 && i)
                return true;
            
            if(mp.find(prefsum) != mp.end()){
                if(i-mp[prefsum]>=2)
                    return true;
            }
            else         //use else to maintain the 1st position of prefsum
                mp[prefsum]=i;
        }
        return false;
    }
};
