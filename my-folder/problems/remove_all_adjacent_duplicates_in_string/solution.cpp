class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";       
        ans.push_back(s[0]);
        if(s.size()>=2)
        {
            for(int i=1;i<s.size();i++)
            {  
                if(ans.size()==0)
                {
                    ans.push_back(s[i]);
                }
                else
                {
                   if(ans[ans.size()-1]!=s[i])
                {
                    ans.push_back(s[i]);   
                }
                else if(ans[ans.size()-1]==s[i] && ans.size()>=1)
                {
                    ans.pop_back();
                }
            }
            }
        }
        return ans;
    }
};