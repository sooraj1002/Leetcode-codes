class Solution {
public:
    int titleToNumber(string s) {
        int sum=0;
        vector<int> v;
        int l=s.length()-1;
        for(int i=0;i<s.length();i++)
        {
            int temp=int(s[i])-64;
            sum=sum+temp*pow(26,l);
            l--;
        }
        return sum;
    }
};