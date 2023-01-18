class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int start=0;
        int end=arr.size()-1;
        int ans;
        while(start <end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]>arr[mid+1])
            end=mid; //not mid-1 as we dont know if mid is max or not

            else if(arr[mid]<arr[mid+1])
            start=mid+1;
        }
        return start;
    }
};