class Solution {
public:
    vector<int> numberOfLines(vector<int>& w, string s) {
        vector<int> ans;
        int width=0;
        int line=1;
        for(int i=0;i<s.size();i++)
        {
            int p=(int)s[i]-97;
            width=width+w[p];
            if(width>100)
            {
                width=width-w[p];
                cout<<width<<endl;
                width=w[p];
                line++;
            }
        }
        ans.push_back(line);
        ans.push_back(width);
        return ans;
    }
};