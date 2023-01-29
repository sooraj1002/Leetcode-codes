class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans=INT_MIN;
        int i=0;
        int j=h.size()-1;
        while(i<j)
        {
            int t = min(h[i], h[j]);
            ans = max(ans, (j - i) * t);
            while (h[i] <= t && i < j) 
                i++;
            while (h[j] <= t && i < j) 
                j--;
        }
        return ans;
    }
};