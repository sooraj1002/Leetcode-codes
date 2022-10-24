class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int flag=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int  j=0;j<arr.size();j++)
            {
                if(arr[i]==arr[j]*2 || (arr[i]==arr[j]/2 && arr[j]%2==0) )
                {
                    if(i !=j)
                    {
                    flag=1;
                    break;}
                }
            }
            if(flag==1)
                break;
        }
        return (flag==1);
    }
};