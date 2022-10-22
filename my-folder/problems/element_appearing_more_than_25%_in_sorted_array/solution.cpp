class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int i=0,count=1,l=arr.size();
        if(l>1)
        {for(;;i++)
        {
            if(arr[i]==arr[i+1])
            {
                count++;
                if(count>l/4)
                    break;
            }
            else
                count=1;
        }}
        return arr[i];
    }
};