class Solution {
public:
    int countOperations(int n1, int n2) {
        int count=0;
        if(n1==0 || n2==0)
            return 0;
        while(n1)
        {
            if(n2>n1)
                n2=n2-n1;
            else
                n1=n1-n2;
            count++;
            if(n1==0 || n2==0)
                break;
        }
        return count;
    }
};