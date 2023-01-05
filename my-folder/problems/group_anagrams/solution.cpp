class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp; 
        map<string,list<int>> m;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            m[s].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto i:m)
        {
            // cout<<i.first<<endl;
            vector<string> t;
            for(auto j:i.second)
            {
                string temp=strs[j];
                t.push_back(temp);
            }
            sort(t.begin(),t.end());
            ans.push_back(t);
        }
        return ans;
    }
};