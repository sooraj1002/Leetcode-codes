class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int k=1;
        if(n%2==1)
        {
            ans.push_back(0);
            for(int i=0;i<n-1;k++,i+=2)
            {
                ans.push_back(k);
                ans.push_back(-1*k);
            }
        }
        else
        {
            for(int i=0;i<n;i +=2,k++)
            {
                ans.push_back(k);
                ans.push_back(-1*k);
            }
        }
        return ans;
    }
};