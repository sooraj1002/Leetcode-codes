class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it:stones){
            pq.push(it);
        }
        while(pq.size()>=2){  //we have 2 elements to compare
            int t=pq.top();
            pq.pop();
            int t1=pq.top();
            pq.pop();
            pq.push(abs(t1-t));
        }
        return pq.top();
    }
};