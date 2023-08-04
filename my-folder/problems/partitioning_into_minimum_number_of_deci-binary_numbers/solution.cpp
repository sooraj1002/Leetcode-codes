class Solution {
public:
    int minPartitions(string s) {
        int maxi=0;
        for(auto it:s){
            int t=it-'0';
            maxi=max(t,maxi);
        }
        return maxi;
    }
};