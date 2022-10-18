class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0,flag=0,l=s.size();
        for(;i<l;i++)
        {
            if(s[i] != t[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            return t[l];  
        return t[i];       
    }
};