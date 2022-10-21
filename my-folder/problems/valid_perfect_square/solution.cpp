class Solution {
public:
    bool isPerfectSquare(long int num) {
        long int i=1,s=0;
        for(;s<num;i=i+2)
        {s=s+i;
        cout<<s<<endl;}
        return s==num;
    }
};