class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            if (arr[i]==0)
            {
                arr.push_back(0);
                int j=arr.size()-1;
                while(j != i)
                {
                    arr[j]=arr[j-1];
                    j--;
                }
                arr[i+1]=0;
                i++;
                count++;
            }
        }
        for(int i=0;i<count;i++)
            arr.pop_back();
    }
};