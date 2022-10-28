class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> c ;
        int n=nums.size();
       
        for(int i=0;i<n;i++)
        {  int flag=0;
            for(int j=i+1;j<n;j++)
            {    if(nums[i]+nums[j]==target)
                 {
                c.push_back(i);
                  c.push_back(j);
                flag=1;
                    break;
                 }
            }
            if(flag==1)
                break;
        }
        return c ;
    }
  
};