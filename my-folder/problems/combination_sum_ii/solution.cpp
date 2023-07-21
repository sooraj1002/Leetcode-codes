class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &candidates,int target,vector<int> &curr,int index){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(index<0 || target <0){
            return;
        }
        curr.push_back(candidates[index]);
        solve(ans,candidates,target-candidates[index],curr,index-1);     //take
        curr.pop_back();
        while(index > 0 &&  candidates[index-1]==candidates[index]){
            index--;
        }
        solve(ans,candidates,target,curr,index-1);   //not_take
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(ans,candidates,target,temp,candidates.size()-1);
        return ans;
    }
};