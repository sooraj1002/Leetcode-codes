class Solution {
public:
    void solve(int n,vector<vector<int>> &ans,vector<int> &curr,int num,int k){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        if(num==n+1)
            return;
        curr.push_back(num);
        solve(n,ans,curr,num+1,k);
        curr.pop_back();
        solve(n,ans,curr,num+1,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(n,ans,curr,1,k);
        return ans;
    }
};