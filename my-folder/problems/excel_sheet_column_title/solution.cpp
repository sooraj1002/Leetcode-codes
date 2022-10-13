class Solution {
public:
    string convertToTitle(int n) {
        int n1=n;
        string s;
        int len=0;
        for(;len<n;len++)
        {
            if(n<pow(26,len))
                break;
        }
        int r=len-1;
        int num=26*(pow(26,len-1)/25);
        cout<<pow(26,len-1)<<endl;
        if(len>2 && (n>=pow(26,len-1)) && (n<num))
        {
            len--;
        }
        if (n==26)
            len=1;
        cout<<len<<endl;
         int count=0;
        vector<int> v;
        int j=len;            
        for(int k=0;k<len;k++,j--)
        {
            
            int s=pow(26,j-1);
            int s1=s;
            
            for(;s<n1;)
            {
                n1=n1-s;
                count++;
            }
            v.push_back(count-1);
            count=0;
        }
        for(int i=0;i<len-1;i++)
            s.push_back(char(v[i]+65));
        s.push_back(char(v[len-1]+66));
        return s;
    }
};