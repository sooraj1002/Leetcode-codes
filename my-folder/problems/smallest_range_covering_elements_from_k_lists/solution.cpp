class Solution {
public:
    bool cmp(vector<int> &a,vector<int> &b){
        return a[0]>b[0];
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){

            if(nums[i][0]>maxi)
                maxi=nums[i][0];
            if(nums[i][0]<mini)
                mini=nums[i][0];

            pq.push({nums[i][0],i,0});
        }
        int ansStart=mini,ansEnd=maxi;
        while(!pq.empty()){

            auto temp=pq.top();
            pq.pop();

            mini=temp[0];     //new start
            int row=temp[1];
            int col=temp[2];

            if(maxi-mini < ansEnd-ansStart){    //if this is a more favourable range then we update the answer
                ansStart=mini;
                ansEnd=maxi;
            }
            
            if(col+1<nums[row].size()){      //checking if any more elements are available for consideration
                maxi=max(maxi,nums[row][col+1]);
                pq.push({nums[row][col+1],row,col+1});
            }
            else{         //if one array has been exhausted then no more possibilities are left
                break;
            }
        }
        return {ansStart,ansEnd};
    }
};