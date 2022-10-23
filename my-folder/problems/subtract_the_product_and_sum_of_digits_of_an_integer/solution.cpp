class Solution {
public:
    int subtractProductAndSum(int n) {
      int s=0,p=1;
        while(n !=0)
      {
            int t=n%10;
            p=p*t;
            s=s+t;
          n=n/10;
      }
        cout<<p<<endl;
        cout<<s<<endl;
        return p-s;
    }
};