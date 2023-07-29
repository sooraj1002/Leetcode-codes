class Solution {
public:
    //MOORE'S VOTING ALGORITHM ALGORITHM
    int majorityElement(vector<int>& nums) {
        int ele=0;
        int count=0;
        for(auto it:nums){
            if(count==0){
                ele=it;
                count++;
            }
            else if(it==ele){
                count++;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};