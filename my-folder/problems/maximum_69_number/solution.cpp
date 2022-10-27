class Solution {
public:
    int maximum69Number (int num) {
        vector<int> v,v1;
        while(num !=0)
        {
            v.push_back(num%10);
            num=num/10;
        }
        for(int i=v.size()-1;i>-1;i--)
            v1.push_back(v[i]);
        v=v1;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==6)
            {
                v[i]=9;
                break;
            }
        }
        int n=0;
        for(int i=v.size()-1,k=0;i>-1;i--,k++)
        {
            n=n+v[i]*pow(10,k);
        }
        return n;
    }
};