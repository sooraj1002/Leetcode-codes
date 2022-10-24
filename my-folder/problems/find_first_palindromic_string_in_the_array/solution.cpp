class Solution {
public:
    int pali(string s){
        int l=s.size();
        for(int i=0;i<l/2;i++)
        {
            if(s[i] != s[l-1-i])
                return 0;
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        string s;
        int flag=0;
        for(int i=0;i<words.size();i++)
        {
            s=words[i];
            if(pali(s)==1)
            {
                flag=1;
                break;
            }
        }
        string a;
        if(flag==1)
            return s;
        return a;
    }
};