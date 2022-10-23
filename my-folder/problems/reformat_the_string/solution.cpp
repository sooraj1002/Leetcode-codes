class Solution {
public:
    string reformat(string s) {
        int count=0;
        string ans,l,n;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a'&& s[i]<='z')
            {
                l.push_back(s[i]);
                count++;
            }
            else
            {
                n.push_back(s[i]);
            }
        }
        int n1=n.size(),l1=l.size();
        if(n1==1 && l1==0)
            ans.push_back(n[0]);
        else if(n1==0 && l1==1)
            ans.push_back(l[0]);
        else if(n1==l1)
        {
            for(int i=0;i<n1;i++)
            {
                ans.push_back(n[i]);
                ans.push_back(l[i]);
            }
        }
        else if(n1==(l1+1))
        {
            for(int i=0;i<l1;i++)
            {
                ans.push_back(n[i]);
                ans.push_back(l[i]);
            }
            ans.push_back(n[l1]);
        }
        else if(l1==(n1+1))
        {
            for(int i=0;i<n1;i++)
            {
                ans.push_back(l[i]);
                ans.push_back(n[i]);
            }
            ans.push_back(l[n1]);
        }
        else if(n1 != l1)
            return ans;
        return ans;
    }
};