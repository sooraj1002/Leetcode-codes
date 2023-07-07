class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(auto i:nums){
            int t=i-x;
            if(pq.size()<k){
                pq.push({t,i});
            }
            else{
                if(abs(t)<abs(pq.top().first)){
                    pq.pop();
                    pq.push({t,i});
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};