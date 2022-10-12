class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int l=words.size();
        int count=0;
        int ans=0;
        for(int i=0;i<l;i++)
        {
            string s=words[i];
            for(int j=0;j<s.size();j++)
            {
                for(int k=0;k<allowed.size();k++)
                {
                    if(s[j]==allowed[k])
                    {
                        count++;
                        break;
                    }
                }              
            }
            if (count==s.size())
                    ans++;
            count=0;
        }
        return ans;
    }
};