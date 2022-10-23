class Solution {
public:
    int balancedStringSplit(string s) {
        int r=0,l=0,count=0;
        if(s[0]=='R')
        {
            r++;
            for(int i=1;i<s.size();i++)
            {
                if(s[i]=='L')
                {
                    r--;
                }
                else
                    r++;
                if(r==0)
                {
                    count++;
                }
            }
        }
        else
        {
            l++;
            for(int i=1;i<s.size();i++)
            {
                if(s[i]=='R')
                {
                    l--;
                }
                else
                    l++;
                if(l==0)
                    {
                        count++;
                    }
            }
        }
        return count;
    }
};