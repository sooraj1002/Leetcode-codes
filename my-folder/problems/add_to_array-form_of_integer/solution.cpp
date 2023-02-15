class Solution {
public:

    void rev(vector<int> &arr){
        for(int i=0;i<arr.size()/2;i++)
        {
            swap(arr[i],arr[arr.size()-i-1]);
        }
    }

    vector<int> addToArrayForm(vector<int>& nums, int k) {
        rev(nums);
        int carry=0;
        int index=0;
        while((k != 0 || carry==1)&& index<nums.size()){
            int d=k%10+carry+nums[index];
            nums[index]=d%10;
            k /=10;
            carry=d/10;
            index++;
        }
        while(k != 0 || carry==1){
            int d=k%10+carry;
            nums.push_back(d%10);
            carry=d/10;
            k /=10;
        }
        rev(nums);
        return nums;
    }
};