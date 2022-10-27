class Solution {
public:
    int numberOfSteps(int n) {
        int count=0;
        if(n==0)
            return 0;
        while(n)
        {
            if(n%2==0)
            {
                n=n/2;
            }
            else
            {
                n--;
            }
            count++;
            if(n==0)
                break;
        }
        return count;
    }
};