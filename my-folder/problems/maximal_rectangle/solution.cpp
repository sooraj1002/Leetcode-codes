class Solution {
public:
    vector<int> nextsmaller(vector<int> arr)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(arr.size());
        for(int i=arr.size()-1;i>-1;i--)
        {
            int t=arr[i];
            while(st.top() != -1 &&  arr[st.top()]>=t){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevsmaller(vector<int> arr)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++)
        {
            int t=arr[i];
            while(st.top() != -1 &&  arr[st.top()]>=t){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> heights) {
        vector<int> next=nextsmaller(heights);
        vector<int> prev=prevsmaller(heights);

        int ans=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            auto l=heights[i];

            if(next[i]==-1)
            next[i]=heights.size();    //if array runs out (all same)
            
            int b=next[i]-prev[i]-1;
            int t=l*b;
            ans = max(ans,t);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> m;
        vector<int> t(matrix[0].size());
        for(int i=0;i<matrix.size();i++)
        {
            m.push_back(t);
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                m[i][j]= matrix[i][j]=='0' ? 0 : 1 ;
            }
        }
        int ans=largestRectangleArea(m[0]);
        for(int i=1;i<m.size();i++)
        {
            for(int j=0;j<m[0].size();j++)
            {
                if(m[i][j]==0)
                continue;
                m[i][j]=m[i-1][j]+m[i][j];
            }
            ans=max(largestRectangleArea(m[i]),ans);
        }
        return ans;
    }
};