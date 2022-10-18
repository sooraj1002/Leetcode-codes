class Solution {
public:
    
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==nums[i]%2)
            {}
            else if(i%2==0)
            {
                for(int j=i+1;j<nums.size();j++)
                {
                   if(j%2  != nums[j]%2 && j%2 ==1)
                   {
                       int temp=nums[i];
                       nums[i]=nums[j];
                       nums[j]=temp;
                       break;
                   }
                }
            }
            else 
            {
                for(int j=i+1;j<nums.size();j++)
                {
                   if(j%2  != nums[j]%2 && j%2 ==0)
                   {
                       int temp=nums[i];
                       nums[i]=nums[j];
                       nums[j]=temp;
                       break;
                   }
                }
            }
        }
        return nums;
    }
};