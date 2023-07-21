class Solution {
public:
    int maxi;
    void solve(vector<int> &nos,vector<int> &curr,vector<vector<int>> &ans,int index,int target){
        if(curr.size()==maxi){
            if(target==0){
                ans.push_back(curr);
                return;
            }
            else{
                return;
            }
        }
        if(target<0 || index<0){
            return;
        }
        solve(nos,curr,ans,index-1,target);
        curr.push_back(nos[index]);
        solve(nos,curr,ans,index-1,target-nos[index]);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nos;
        for(int i=1;i<10;i++){
            nos.push_back(i);
        }
        maxi=k;
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nos,curr,ans,8,n);
        return ans;
    }
};