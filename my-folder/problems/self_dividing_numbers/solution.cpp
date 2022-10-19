class Solution {
public:
    int check(int n){
        while(n!=0)
        {
            if(n%10==0)
                return 1;
            n=n/10;
        }
        return 0;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        int flag=0;
        for(int i=left;i<=right;i++)
        {
            int n=i;
            int temp;
            int f=check(n);
            if(n%10 !=0 && f ==0)
            {
               while(n != 0)
               {
                   temp=n%10;
                   if(i%temp != 0)
                   {
                      flag=1;
                      break;
                    }
                    n=n/10;
               }
               if(flag ==0)
                   ans.push_back(i);
               flag=0;
           }
       }
        return ans;
    }
};