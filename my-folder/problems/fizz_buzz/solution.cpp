class Solution {
public:
    int sum(int n){
        int s=0;
        while(n!=0)
        {
            s=s+n%10;
            n=n/10;
        }
        return s;
    }
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++)
        {
            int s=sum(i);
            if(s%3==0 && i%5==0)
                ans.push_back("FizzBuzz");
            else if(s%3==0)
                ans.push_back("Fizz");
            else if(i%5==0)
                ans.push_back("Buzz");
            else
            {
                string s=to_string(i);
                ans.push_back(s);
            }
        }
        return ans;
    }
};