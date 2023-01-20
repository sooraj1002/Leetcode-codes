class Solution {
public:

    bool check(vector<int>& piles,int h,int m)
    {
        long long int count=0;
        // cout<<"m   "<<m<<endl;
        for(auto i:piles)
        {
            int t;
            if(i%m != 0)
            t=i/m+1;
            else
            t=i/m;
            count += t; 
            // cout<<t<<endl;
        }
        return count <=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max=piles[0];      //stores the max number of bananas in 1 hr
        for(auto i:piles)
        {
            if(i>max)
            max=i;
        }
        // cout<<"max  "<<max<<endl;
        int start=1;
        int end=max;
        int ans;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int sum;
            if(check(piles,h,mid))
            {
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return start;
    }
};