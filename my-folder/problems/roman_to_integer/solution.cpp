class Solution {
public:
    int romanToInt(string s) {
        int l=s.length();
        int i=0;
        int n=0;
        for(;i<l;i++)
        {
            if(s[i]=='I' && s[i+1]=='V')
            {
                n=n+4;
                i++;
            }
            else if(s[i]=='I' && s[i+1]=='X')
            {
                n=n+9;
                i++;
            }
            else if(s[i]=='X' && s[i+1]=='L')
            {
                n=n+40;
                i++;
            }
            else if(s[i]=='X' && s[i+1]=='C')
            {
                n=n+90;
                i++;
            }
            else if(s[i]=='C' && s[i+1]=='D')
            {
                n=n+400;
                i++;
            }
            else if(s[i]=='C' && s[i+1]=='M')
            {
                n=n+900;
                i++;
            }
            else if(s[i]=='I')n+=1;
            else if(s[i]=='V')n+=5;
            else if(s[i]=='X')n+=10;
            else if(s[i]=='L')n+=50;
            else if(s[i]=='C')n+=100;
            else if(s[i]=='D')n+=500;
            else if(s[i]=='M')n+=1000;
                
        }
        return n;
    }
};