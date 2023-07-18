class Solution {
public:

    void shiftLeft(vector<int> &nums,int index){
        for(int i=index;i<nums.size()-1;i++){
            swap(nums[i],nums[i+1]);
        }
    }

    int removeDuplicates(vector<int>& nums) {
        int count=0;
        bool flag=0; //tells if we have two same elements
        int temp;//stores the element already occoured twice
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(flag && nums[i]==temp){
                count++;
                shiftLeft(nums,i);
                n--;
                i--;
            }
            else{
                flag=0;
            }
            if(nums[i]==nums[i-1]){
                flag=1;
                temp=nums[i];
            }
        }
        return nums.size()-count;
    }
};