class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        queue<char> q;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            m[c]++;
            cout<<c<<" ";
            // cout<<m.find(c)->second<<endl;
            if(m.find(c)->second<2)
            {
                q.push(c);
            }
            else
            {
                while(!q.empty() && q.front() != c)
                {
                    m[q.front()]--;
                    q.pop();
                }
                while(!q.empty() && q.front()==c)
                {
                    m[q.front()]--;
                    q.pop();
                }
                q.push(c);
            }
            int t=q.size();
            cout<<t<<endl;
            ans=max(t,ans);
        }
        return ans;
    }
};