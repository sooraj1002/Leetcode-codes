class Solution {
public:
    string reverseWords(string s) {
        int j=0,k;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                k=i-1;
                while(k>=j)
                {
                    ans.push_back(s[k]);
                    k--;
                }
                ans.push_back(' ');
                j=i+1;
            }
        }
        for(int i=s.size()-1;i>=j;i--)
        {
            ans.push_back(s[i]);
        }
        return ans;
    }
};