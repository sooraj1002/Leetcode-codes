class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int count=0;
        if(s.size() != goal.size())
            return false;
        int a=-1,b=-1;
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            if(s[i] != goal[i]){
                count++;
                if(a==-1)
                    a=i;
                else if(b==-1)
                    b=i;
            }
            if(count>2){
                return false;
            }
        }
        if(count==0){
            for(auto i:mp){
                if(i.second>1)
                    return true;
            }
            return false;
        }
        if(count==1)
            return false;
        return s[a]==goal[b] && goal[a]==s[b];
    }
};