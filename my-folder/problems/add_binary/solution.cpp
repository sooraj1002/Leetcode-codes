#include <bits/stdc++.h>
class Solution {
public:

    string rev(string s){
        string ans;
        for(auto it=s.rbegin();it != s.rend();it++)
        ans.push_back(*it);
        return ans;
    }

    string addBinary(string a, string b) {
        auto it1=a.rbegin();
        auto it2=b.rbegin();
        string ans;
        int carry=0;
        while(it1 != a.rend() && it2 != b.rend()){
            int t1=*it1-'0',t2=*it2-'0',n=t1+t2+carry;
            if(n>1){
                n=n-2;
                carry=1;
            }
            else
            carry=0;
            char c=n+'0';
            ans.push_back(c);
            it1++;
            it2++;
        }
        while(it1 != a.rend()){
            int t=*it1-'0'+carry;
            if(t>1){
                t=t-2;
                carry=1;
            }
            else
            carry=0;
            char c=t+'0';
            ans.push_back(c);
            it1++;
        }
        while(it2 != b.rend()){
            // cout<<"F"<<endl;
            int t=*it2-'0'+carry;
            if(t>1){
                t=t-2;
                carry=1;
            }
            else
            carry=0;
            char c=t+'0';
            ans.push_back(c);
            it2++;
        }
        if(carry==1)
        ans.push_back('1');
        ans=rev(ans);
        return ans;
    }
};