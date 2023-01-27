class Solution {
public:

    int binsrch(vector<int> arr,int target)
    {
        int start=0;
        int end=arr.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start/2);
            if(arr[mid]==target)
            return mid;
            else if(target<arr[mid])
            end=mid-1;
            else
            start=mid+1;
        }
        return -1;
    }

    bool search(vector<vector<int>> &arr,int target)
    {
        int start=0;
        int end=arr.size()-1;
        bool ans=0;
        int mid;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(arr[mid][0]==target)
            return true;
            else if(target < arr[mid][0])
            end=mid-1;
            else
            start=mid+1;
        }
        // cout<<"start "<<start<<endl;
        // cout<<"mid  "<<mid<<endl;
        // cout<<"end  "<<end<<endl;
        if(end==-1)
        return false;

        int a=binsrch(arr[end],target);
        
        if(a==-1)
        return false;
        else
        return true;
        // return 1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans=search(matrix,target);
        return ans;
    }
};