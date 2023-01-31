class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // vector<bool> truth(target.size(),0);
        vector<string> ans;
        stack<int> st;
        int count=0;
        for(int i=1,k=0;i<=n;i++)
        {
            st.push(i);
            if(st.top()==target[k]){
                k++;
                ans.push_back("Push");
                if(k==target.size())
                    return ans;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
                st.pop();
            }
        }
        return ans;
    }
};