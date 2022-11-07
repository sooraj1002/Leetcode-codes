class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
      vector<int> ans;
        for(int i=0;i<index.size();i++)
        {
            int l=ans.size();
            if(index[i]>=l)
            {
                cout<<"l1"<<endl;
                ans.push_back(nums[i]);
            }
            else
            {
                cout<<"l2"<<endl;
                int j=index[i];
                int temp=ans[j];
                ans[j]=nums[i];
                ans.push_back(temp);
                // for(int k=j+1;k<ans.size()-1;k++)
                for(int k=ans.size()-2;k>j;k--)
                {
                    ans[k+1]=ans[k];
                }
                ans[j+1]=temp;
            }
            for(int i:ans)
            cout<<i<<" ";
            cout<<endl;
        }
        return ans;  
    }
};