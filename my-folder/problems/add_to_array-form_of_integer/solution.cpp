class Solution {
public:
    vector<int> rev(vector<int>& v){
        vector<int> v1;
        for(int i=v.size()-1;i>-1;i--)
        {
            int t1=v[i];
            v1.push_back(t1);
        }
        return v1;
    }
    
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        vector<int> v,v1,ans;
        int flag=0;
        while(k != 0)
        {
            v.push_back(k%10);
            k=k/10;
        }
        if(v.size()>num.size())
        {
            vector<int> temp=v;
            v=rev(num);
            num=temp;
            flag=1;
        }
        while(v.size()-1<num.size()-1)
        {
            v.push_back(0);
        }
        int i=num.size()-1;
        
        v1=rev(v);
        if(flag==1)
            num=rev(num);
        int carry=0;
        for(;i>0;i--)
        {
            int n=num[i]+v1[i]+carry;
            if(n>9)
            {
                ans.push_back(n-10);
                carry=1;
            }
            else
            {
                ans.push_back(n);
                carry=0;
            }
        }
        if(num[0]+v1[0]+carry>9)
        {
            ans.push_back(num[0]+v1[0]+carry-10);
            ans.push_back(1);
        }
        else
        {
            ans.push_back(num[0]+v1[0]+carry);
        }
        ans=rev(ans);
        return ans;
        
        
    }
};