class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        unordered_set<int> st;
        for(auto i:s){
            mp[i]++;
        }
        int count=0;
        for(auto it:mp){
            int n=it.second;
            if(st.find(n)==st.end()){
                st.insert(n);
            }
            else{
                int t=n;
                while(st.find(t) != st.end()){
                    t--;
                    count++;
                    if(t==0){
                        break;
                    }
                    if(st.find(t)==st.end()){
                        st.insert(t);
                        break;
                    }
                }
            }
        }
        return count;
    }
};