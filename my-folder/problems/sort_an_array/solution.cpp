class Solution {
public:
    void heapsort(vector<int> &nums){
        int t=nums.size();
        while(t>0){
            swap(nums[t-1],nums[0]);
            t--;

            heapify(nums,0,t);
        }
    }
    void heapify(vector<int> &nums,int index,int n){
        int largest=index;
        int left=2*index;
        int right=2*index+1;

        if(left<n && nums[left]>nums[largest]){
            largest=left;
        }
        if(right<n && nums[right]>nums[largest]){
            largest=right;
        }
        if(largest != index){
            swap(nums[index],nums[largest]);
            heapify(nums,largest,n);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=(n-1)/2;i>=0;i--){
            heapify(nums,i,nums.size());
        }
        heapsort(nums);
        return nums;
    }
};