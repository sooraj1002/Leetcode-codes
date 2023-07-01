class Solution {
public:
    void add(int num,priority_queue<int> &first,priority_queue<int,vector<int>,greater<>> &second){
        if(first.empty() || first.top()>num){
            first.push(num);
        }
        else{
            second.push(num);
        }

        if(first.size()>second.size()+1){
            second.push(first.top());
            first.pop();
        }
        else if(second.size()>first.size()+1){
            first.push(second.top());
            second.pop();
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> first;   //stores first half of sorted array
        priority_queue<int,vector<int>,greater<>> second;  //stores second half of sorted array

        for(auto i:nums1){
            add(i,first,second);
        }
        for(auto i:nums2){
            add(i,first,second);
        }
        if(first.size()==second.size()){
            return double(first.top()+second.top())/2;
        }
        else{
            if(first.size()>second.size())
                return double(first.top());
            else
                return double(second.top());
        }
    }
};