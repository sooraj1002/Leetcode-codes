class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if(s1.size() != s2.size()){
            return false;
        }
        vector<int> v1(26,0),v2(26,0);
        for(auto it:s1){
            v1[it-'a']++;
        }
        for(auto it:s2){
            v2[it-'a']++;
        }
        for(int i=0;i<26;i++){
            if((v1[i]>0 && v2[i]==0 )|| (v2[i]>0 && v1[i]==0)){
                return false;
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2;
    }
    // bool closeStrings(string s1, string s2) {
    //     if(s1.size() != s2.size()){
    //         return false;
    //     }
    //     sort(s1.begin(),s1.end());
    //     sort(s2.begin(),s2.end());
    //     if(s1==s2){
    //         return true;
    //     }
    //     unordered_set<char> st;
    //     unordered_map<char,int> mp,mp1;
    //     for(auto it:s1){
    //         st.insert(it);
    //         mp[it]++;
    //     }
    //     for(auto it:s2){
    //         mp1[it]++;
    //         if(st.find(it)==st.end()){
    //             return false;
    //         }
    //     }
    //     map<int,int> mp2; //stores the number of occourances
    //     for(auto it:mp){
    //         mp2[it.second]++;
    //     }
    //     for(auto it:mp1){
    //         mp2[it.second]--;
    //     }
    //     for(auto it:mp2){
    //         if(it.second != 0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
};