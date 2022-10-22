class Solution {
public:
    string rev(string& s){
        string s1;
        for(int i=s.size()-1;i>-1;i--)
        {
            char c=s[i];
            s1.push_back(c);
        }
        return s1;
    }
    string addStrings(string n1, string n2) {
        string ans;
        int l1=n1.size();
        int l2=n2.size();
        string t;
        if(l1>l2)
        {
            
            for(int i=0;i<l1-l2;i++)
                t.push_back('0');
            t=t+n2;
            n2=t;
        }
        else
        {
            for(int i=0;i<l2-l1;i++)
                t.push_back('0');
            t=t+n1;
            n1=t;
        }
        int carry=0;
        for(int i=n1.size()-1;i>0;i--)
        {
            int a=(int)n1[i]-48;
            int b=(int)n2[i]-48;
            int n=a+b+carry;
            if(n>9)
            {
                ans.push_back(char(n-10+48));
                carry=1;
            }
            else
            {
                ans.push_back(char(n+48));
                carry=0;
            }       
        }
        if((int)n1[0]+(int)n2[0]+carry-96>9)
        {
            ans.push_back(char((int)n1[0]+(int)n2[0]+carry-96-10+48));
            ans.push_back('1');
        }
        else
        {
            ans.push_back((int)n1[0]+(int)n2[0]+carry-96+48);
        }
        ans=rev(ans);
        return ans;
    }
};