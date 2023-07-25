class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int max_dist) {
        vector<vector<int>> matrix(n,vector<int>(n,1e9));

        for(auto edge:edges){
            int parent=edge[0];
            int child=edge[1];
            int wt=edge[2];

            matrix[parent][child]=wt;
            matrix[child][parent]=wt;
        }

        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }

        for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
	            }
	        }
	    }

        vector<int> dist(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // cout<<matrix[i][j]
                if(i==j)
                    continue;
                if(matrix[i][j]<=max_dist){
                    dist[i]++;
                }
            }
        }
        int ans=0,mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(dist[i]<=mini){
                ans=i;
                mini=dist[i];
            }
        }
        return ans;
    }

};