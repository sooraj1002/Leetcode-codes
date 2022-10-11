class Solution {
public:
    string interpret(string s) {
        int l=s.length();
        string s2;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='G')
                s2.push_back('G');
            else if(s[i]=='a')
            {
                s2.push_back('a');
                s2.push_back('l');
            }
            
            else if(i+1<l)
            {
                if(s[i]=='(' && s[i+1]==')')
                s2.push_back('o');
            }
        }
        return s2;
    }
};