class Solution {
public:
    void dfs(vector<vector<int>> &img,vector<vector<int>> &vis,int check,int i,int j,int color,int m,int n){
        img[i][j]=color;
        vis[i][j]=1;
        if(i>0 && img[i-1][j]==check && !vis[i-1][j]){
            dfs(img,vis,check,i-1,j,color,m,n);
        }
        if(j>0 && img[i][j-1]==check && !vis[i][j-1]){
            dfs(img,vis,check,i,j-1,color,m,n);
        }
        if(i<m-1 && img[i+1][j]==check && !vis[i+1][j]){
            dfs(img,vis,check,i+1,j,color,m,n);
        }
        if(j<n-1 && img[i][j+1]==check && !vis[i][j+1]){
            dfs(img,vis,check,i,j+1,color,m,n);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int check=image[sr][sc];
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        dfs(image,vis,check,sr,sc,color,m,n);
        return image;
    }
};