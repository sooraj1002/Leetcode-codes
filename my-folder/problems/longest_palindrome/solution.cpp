class Solution {
public:
    int longestPalindrome(string s) {
        int even=0,odd=0;
        sort(s.begin(),s.end());
        for(int i=0;i<s.size();)
        {
            if(s[i]==s[i+1])
            {
                even++;
                i=i+2;
            }
            else
            {
                odd++;
                i++;
            }
        }
        if(odd>0)
            odd=1;
        return 2*even+odd;
    }
};