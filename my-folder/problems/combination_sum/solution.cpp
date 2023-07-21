class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &candidates,int target,vector<int> &curr,int index){
        if(index<0 || target <0){
            return;
        }
        if(target==0){
            // cout<<"hiii"<<endl;
            // auto t=curr;
            // sort(t.begin(),t.end());
            ans.push_back(curr);
            return;
        }
        solve(ans,candidates,target,curr,index-1);   //not_take
        curr.push_back(candidates[index]);
        solve(ans,candidates,target-candidates[index],curr,index);     //take
        curr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // set<vector<int>> st;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,candidates,target,temp,candidates.size()-1);
        // for(auto it:st){
        //     ans.push_back(it);
        // }
        return ans;
    }
};