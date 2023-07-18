class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)
            return;
        if(m==0){
            nums1=nums2;
            return;
        }
        int i=0,j=0;
        vector<int> temp;
        for(;i<m && j<n;){
            if(nums1[i]<nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else{
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            temp.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            temp.push_back(nums2[j]);
            j++;
        }
        int k=0;
        for(auto i:temp){
            nums1[k]=i;
            k++;
        }   
    }
};