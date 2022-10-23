class Solution {
public:
    string freqAlphabets(string s) {
        vector<int> v,a;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')
                v.push_back(85);
            else
                v.push_back(s[i]-48);
        }
        int l=v.size();
        for(int i=0;i<v.size()-2;i++)
        {
           if(v[i+2]==85)
           {
               int t=v[i]*10+v[i+1];
               a.push_back(t);
               i+=2;
           }
            else
            {
                a.push_back(v[i]);
            }
        }
        if(v[l-1] !=85 && v[l-2] !=85)
        {
            a.push_back(v[l-2]);
            a.push_back(v[l-1]);
        }
        else if(v[l-2]==85)
            a.push_back(v[l-1]);
        string ans;
        for(int i:a)
        {
            cout<<i<<" ";
            char c=(char)(i+96);
            ans.push_back(c);
        }
        return ans;
    }
};