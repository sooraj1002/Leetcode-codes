class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        queue<int> q;
        int sum=0;
        for(auto i:nums){
            q.push(i);
            sum+=i;
            if(sum>=target){
                int t=q.size();
                ans=min(ans,t);
            }
            while(sum>=target){
                sum -= q.front();
                int t=q.size();
                ans=min(ans,t);
                q.pop();
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};