class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count=0;
        int curr_sum=0;
        for(int i=0;i<arr.size();i++){
            int expected_sum=(i)*(i+1)/2;
            curr_sum += arr[i];
            if(expected_sum==curr_sum){
                count++;
            }
        }
        return count;
    }
};