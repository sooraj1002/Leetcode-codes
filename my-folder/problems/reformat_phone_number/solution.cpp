class Solution {
public:
    string reformatNumber(string n) {
        string ans;
        string number;
        for(int i=0;i<n.size();i++)
        {
            if(n[i]>='0' && n[i]<='9')
                number.push_back(n[i]);
        }
            
        int num=number.size();
        int i=0;                         //number of groups of 3 digits
        for(;num>4;i++)
        {    
            num=num-3;
        }
        int k=0;
        for(int j=0;j<i;j++)
        {
            ans.push_back(number[k]);
            ans.push_back(number[k+1]);
            ans.push_back(number[k+2]);
            ans.push_back('-');
            k=k+3;
        }
        cout<<number;
        if(num==4)
        {
            ans.push_back(number[k]);
            ans.push_back(number[k+1]);
            ans.push_back('-');
            ans.push_back(number[k+2]);
            ans.push_back(number[k+3]);
        }
        else
        {
            for(;k<number.size();k++)
            {
                ans.push_back(number[k]);
            }
        }
        return ans;
    }
};