class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int  a=0;
        for(int i=0; i<nums.size();i++){
               a=a^nums[i];
        
            // cout<<"num "<<nums[i]<<endl;
            if( i%2==1 && a != 0){
                a=nums[i-1];
                break;
            } 
        }
         
        return a;
    }
};