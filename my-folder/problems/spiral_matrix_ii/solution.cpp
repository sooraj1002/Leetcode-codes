class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,-1));
        int rows=ans.size()-1;
        int cols=ans[0].size()-1;
        int top=0,left=0;     //tells us how many rows from top are done and how many rows from left    are done

        int k=1;
        while(k<=pow(n,2)){
            for(int j=left;j<=cols;j++){
                ans[top][j]=k;    //move right
                k++;
            }
            top++;
            if(top>rows || left>cols) break;

            for(int i=top;i<=rows;i++){
                ans[i][cols]=k;  //move down
                k++;
            }
            cols--;
            if(top>rows || left>cols) break;

            for(int j=cols;j>=left;j--){
                ans[rows][j]=k;  //move back
                k++;
            }
            rows--;
            if(top>rows || left>cols) break;

            for(int i=rows;i>=top;i--){
                ans[i][left]=k;  //move up
                k++;
            }
            left++;
            if(top>rows || left>cols) break;
        }

        return ans;
    }
};