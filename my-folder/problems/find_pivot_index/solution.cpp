class Solution {

public:
    int pivotIndex(vector<int>& nums) {
        // int leftsum = 0;
        int temp = 0;
        for(int i=0; i<nums.size();i++){
           temp=temp+nums[i];
        }
        int x=temp;
//    cout<<temp;
        for(int i=0; i<nums.size();i++){
            x = x - nums[i];
            // cout<<"x  "<<x<<endl;
            int y = x;
            int leftsum=0;
            for(int j = i; j >0 ; j --){  
                leftsum += nums[j-1];
                // cout<<"l "<<leftsum<<endl;
            }
            if (leftsum == y)
                return i; 
        }
       return -1;
    }
};
