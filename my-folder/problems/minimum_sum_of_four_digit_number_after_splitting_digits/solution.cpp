class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        int a,b;
        while(num != 0)
        {
            v.push_back(num%10);
            num=num/10;
        }
        sort(v.begin(),v.end());
        a=v[0]*10+v[2];
        b=v[1]*10+v[3];
        return a+b;
    }
};