class Solution {
public:
    int partitionString(string s) {
        int count=1;
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) != mp.end()){
                map<char,int> t;
                mp=t;
                mp[s[i]]++;
                count++;
            }
            else{
                mp[s[i]]++;
            }

        }
        return count;
    }
};