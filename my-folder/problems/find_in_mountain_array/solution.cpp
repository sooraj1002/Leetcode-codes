/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int maxi(MountainArray &mountainArr)
    {
        int start=0;
        int end=mountainArr.length()-1;
        while(start <end)
        {
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid+1))
            end=mid; //not mid-1 as we dont know if mid is max or not

            else if(mountainArr.get(mid)<mountainArr.get(mid+1))
            start=mid+1;
        }
        return start;
    }

    int binsrch(int target, MountainArray &mountainArr,int start,int end,bool test)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target<mountainArr.get(mid))
            {
                if(test)
                end=mid-1;
                else
                start=mid+1;
            }
            else if(target>mountainArr.get(mid))
            {
                if(test)
                start=mid+1;
                else
                end=mid-1;
            }
            else
            return mid;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int max=maxi(mountainArr);
        int n=mountainArr.length();
        cout<<max<<endl;
        int ans=binsrch(target,mountainArr,0,max,true);
        if(ans==-1)
        {
            cout<<"ye"<<endl;
            int second=binsrch(target,mountainArr,max+1,n-1,false);
            ans=second;
        }
        return ans;
    }
};