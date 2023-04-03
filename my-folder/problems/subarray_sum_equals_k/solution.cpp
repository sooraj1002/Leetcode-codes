class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        map<int,int> mp;  //stores the number of times a particular sum has already occoured
        int count=0;
        int sum=0;       //stores sum of all previous elements     
        mp[0]=1;         //for sum=0, so, acts something like a base case

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remove=sum-target;            
            //if, for a given index, if tot_sum-target has already occoured for consecutive indices,target will also occour in that range  
            count +=mp[remove];
            //add the new sum in the map. if we add before checking count, it will change the result
            mp[sum]++;
        }
        return count;
    }
};