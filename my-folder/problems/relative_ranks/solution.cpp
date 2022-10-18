class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> v=score;
        vector<string> ans;
        sort(score.begin(), score.end(), greater<int>());

        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v.size();j++)
            {
                if(v[i]==score[j])
                {
                    if(j==0)
                    {
                        ans.push_back("Gold Medal");
                        break;
                    }
                    else if(j==1)
                    {
                        ans.push_back("Silver Medal");
                        break;
                    }
                    else if(j==2)
                    {
                        ans.push_back("Bronze Medal");
                        break;
                    }
                    else
                    {
                        ans.push_back(to_string(j+1));  
                        break;
                    }
                }
            }
        }
        return ans;
    }
};