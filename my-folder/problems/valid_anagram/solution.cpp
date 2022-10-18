class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1;
        vector<int> v2;
        for(int i=0;i<s.size();i++)
        {
            int t1=(int)s[i];
            int t2=(int)t[i];
            v1.push_back(t1);
            v2.push_back(t2);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int flag=0;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i] != v2[i])
                flag=1;
        }
        if(flag==1 ||  s.size() != t.size())
            return false;
        return true;
    }
};