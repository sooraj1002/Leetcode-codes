class Solution {
public:
    string defangIPaddr(string a) {
        string ans;
       for(int i=0;i<a.size();i++)
       {
           if(a[i]=='.')
           {
               ans.push_back('[');
               ans.push_back('.');
               ans.push_back(']');
           }
           else
               ans.push_back(a[i]);
       }
        return ans;
    }
};