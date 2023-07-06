class Solution {
public:
    class cmp{
        public:
        bool operator()(pair<double,vector<int>> &a,pair<double,vector<int>> &b){
            return a.first<b.first;
        }
    };
    

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,cmp> pq;
        for(int i=0;i<points.size();i++){
            auto t=make_pair(sqrt(pow(points[i][0],2)+pow(points[i][1],2)),points[i]);
            if(pq.size()<k){
                pq.push(t);
            }
            else{
                if(t.first<pq.top().first){
                    pq.pop();
                    pq.push(t);
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};