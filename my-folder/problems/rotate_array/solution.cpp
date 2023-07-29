class Solution {
public:
    void rotate(vector<int> &nums,int k){
        int n=nums.size();
        k = k%n;

        reverse(nums.begin(),nums.begin()+n-k);   //first (n-k) ele 
        reverse(nums.begin()+n-k,nums.end());     // last k ele

        reverse(nums.begin(),nums.end());         //complete arr
    }
    // void rotate(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<int> temp(n);

    //     for(int i=0;i<n;i++){
    //         temp[(i+k)%n]=nums[i];
    //     }
    //     nums=temp;
    // }
};