class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int l=words.size();
        int ans=0;
        for(int i=0;i<l;i++)
        {
            string w=words[i];
            int count=0;
            for(int j=0;j<pref.size() && j<w.size();j++)
            {
                if(pref[j]==w[j])
                    count++;
            }
            if(count==pref.size())
                ans++;
        }
        return ans;
    }
};