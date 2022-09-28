class Solution {
public:
    int mySqrt(int x) {
        long int i=0;
        while(i*i<x && i<=x/2)
        {
            if((i+1)*(i+1)>x)
                break;
            i++;
        }
        return i;
    }
};