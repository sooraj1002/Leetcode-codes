class Solution {
public:
    int checkzero(int a){
        while(a !=0)
        {
            if(a%10==0)
                return 1;
            a=a/10;
        }
        return 0;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int i=1;i<n;i++)
        {
            int a=i;
            int b=n-i;
            if(checkzero(a)==1 || checkzero(b)==1)
                continue;
            else
            {
                ans.push_back(a);
                ans.push_back(b);
                break;
            }
        }
        return ans;
    }
};