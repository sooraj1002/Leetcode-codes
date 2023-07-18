class Solution {
public:
    void shiftLeft(vector<int> &nums,int index){
        for(int i=index;i<nums.size()-1;i++){
            swap(nums[i],nums[i+1]);
        }
    }
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                count++;
                shiftLeft(nums,i);
                n--;
                i--;
            }
        }
        return nums.size()-count;
    }
};