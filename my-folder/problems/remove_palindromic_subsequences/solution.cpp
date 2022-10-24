class Solution {
public:
    int pali(string s)
    {
        int l=s.size();
        for(int i=0;i<l/2;i++)
        {
            if(s[i]!=s[l-1-i])
                return 1;
        }
        return 0;
    }
    int removePalindromeSub(string s) {
        if(s.size()==0)
            return 0;
        else if(pali(s)==0)
            return 1;
        else 
            return 2;
    }
};