class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size()-1;
        int cols=matrix[0].size()-1;
        int top=0,left=0;     //tells us how many rows from top are done and how many rows from left    are done
        vector<int> ans;

        while(1){
            for(int j=left;j<=cols;j++){
                ans.push_back(matrix[top][j]);    //move right
            }
            top++;
            if(top>rows || left>cols) break;

            for(int i=top;i<=rows;i++){
                ans.push_back(matrix[i][cols]);  //move down
            }
            cols--;
            if(top>rows || left>cols) break;

            for(int j=cols;j>=left;j--){
                ans.push_back(matrix[rows][j]);  //move back
            }
            rows--;
            if(top>rows || left>cols) break;

            for(int i=rows;i>=top;i--){
                ans.push_back(matrix[i][left]);  //move up
            }
            left++;
            if(top>rows || left>cols) break;
        }

        return ans;
    }
};