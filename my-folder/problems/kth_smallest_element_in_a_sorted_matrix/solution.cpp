class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        
        for(int row=0;row<n;row++){
            pq.push({matrix[row][0],row,0});   //push the first element of each row to the min pq
        }
        
        //pq stores elemets in the form [element,row,column] so that we can know what row to enter element from next

        int ans;
        for(int i=0;i<k;i++){
            auto temp=pq.top();
            pq.pop();
            ans=temp[0];
            int row=temp[1],col= temp[2];
            if(col+1<n)
                pq.push({matrix[row][col+1],row,col+1});
        }
        return ans;
    }
};