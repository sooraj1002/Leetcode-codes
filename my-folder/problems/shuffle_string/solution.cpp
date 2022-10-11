class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string s2=s;
        for(int i=0;i<s.size();i++)
        {
            int temp=indices[i];
            s2[temp]=s[i];
        }
        return s2;
    }
};