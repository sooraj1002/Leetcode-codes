class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,int> mp;
        string s1="qwertyuiop";
        string s2="asdfghjkl";
        string s3="zxcvbnm";
        for(int i=0;i<s1.size();i++){
            mp[s1[i]]=1;
            if(i<s2.size())
                mp[s2[i]]=2;
            if(i<s3.size())
                mp[s3[i]]=3;
        }
        int flag=0;
        vector<string> ans;
        for(auto k:words){
            auto i=k;
            transform(i.begin(), i.end(), i.begin(), ::tolower);
            for(int j=0;j<i.size()-1;j++){
                // cout<<i[j]<<" "<<mp[i[j]]<<endl;
                // cout<<i[j+1]<<" "<<mp[i[j+1]]<<endl;
                if(mp[i[j]] != mp[i[j+1]])
                {
                    flag=1;
                }
            }
            if(flag==0)
                ans.push_back(k);
            else
                flag=0;
        }
        return ans;
    }
};