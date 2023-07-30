class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0;
        map<int,int> mp;
        int count=0;
        mp[0]=1;

        for(auto it:nums){
            sum+=it;

            int remove=sum-goal;
            count+=mp[remove];
            mp[sum]++;
        }
        return count;
    }
};