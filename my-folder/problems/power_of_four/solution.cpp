class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
            return true;
        else if(n==2||n==3 ||n<1)
            return false;
        int count=0;
        int flag=0;
        for(int i=0;;i++)
        {
            if((n&(n-1))!=0)
            {
                flag=1;
                break;
            }
            n=n/2;
            count++;
            if(n<2)
            break;
        }
        if(flag==1  || count %2==1)
            return false;
        return true;
    }
};