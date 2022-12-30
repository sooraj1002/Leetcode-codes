class Solution {
public:
    static int comparator(pair<char,int> a,pair<char,int> b)
    {
        return a.second<b.second;
    }
    string frequencySort(string s) {
        map<char,int> m;
        
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]+=1;
        }
        vector<pair<char,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),comparator);
        string ans;
        for(int i=v.size()-1;i>-1;i--)
        {
            for(int j=0;j<v[i].second;j++)
            ans.push_back(v[i].first);
        }
        return ans;
    }
};