class Solution {
public:
    void moze(vector<int>& nums){
        int back=nums.size()-1;
        int l=nums.size()-1;
        for(int i=0;i<l;i++)
        {
            if(nums[i]==0)
            {
                for(int j=i;j<l;j++)
                {
                    nums[j]=nums[j+1];
                }
                nums[back]=0;
                l--;
                back--;
            }
        }
    }
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int flag=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==0)
            {
                for(int j=i+1;j<nums.size();j++)
                {
                    if(nums[j] != 0)
                    flag=1;
                }
            }
        }
        if(flag==1)
        {
            moze(nums);
            moveZeroes(nums);
        }
    }
};