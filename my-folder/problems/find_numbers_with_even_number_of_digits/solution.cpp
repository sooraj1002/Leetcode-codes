class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            int n=nums[i];
            int c1=0;
            while(n!=0)
            {
                n=n/10;
                c1++;
            }
            if(c1%2==0)
                count++;
        }
        return count;
    }
};