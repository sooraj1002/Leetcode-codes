class Solution {
public:
    bool isPalindrome(string s) {
       int i=s.length();
        string s2;
        for(int j=0;j<i;j++)
        {
            if(s[j]>='A' && s[j]<='Z')
            {
                s[j]=s[j]+32;
            }
            if((s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9'))
            s2.push_back(s[j]);
        }
        int flag=0;
        int l=s2.size();
        if(l%2 != 0)
            l--;
        int length=s2.length();
        cout<<s2;
        for(int j=0;j<(l/2);j++)
        {
            if(s2[j]!=s2[length-1])
            {
                flag=1;
                break;
            } 
            length--;
        }
        if(flag==1)
            return false;
        return true;
    }
    
};