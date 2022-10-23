class Solution {
public:
    void rem(vector<int>& v,int j){
        int l=v.size();
    for(;j<l-1;j++)
    {
        v[j]=v[j+1];
        // l--;
    }
    }
    
    vector<int> relativeSortArray(vector<int>& a1, vector<int>& a2) {
        vector<int> ans;
        int l=a1.size();
        for(int i=0;i<a2.size();i++)
        {
            for(int j=0;j<l;j++)
            {
                if(a1[j]==a2[i])
                {
                    ans.push_back(a2[i]);
                }
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<a1.size();j++)
            {
                if (ans[i]==a1[j])
                    rem(a1,j);
            }
        }
        vector<int> v1;
        for(int i=0;i<a1.size()-ans.size();i++)
            v1.push_back(a1[i]);
        sort(v1.begin(),v1.end());
        for(int i:v1)
            ans.push_back(i);
        return ans;
    }
};