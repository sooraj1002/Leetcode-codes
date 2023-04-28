#define ll long long

class Solution {
public:

    int maxChunksToSorted(vector<int>& arr){
        stack<int> st;
        st.push(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(!st.empty() && arr[i]>st.top()){
                st.push(arr[i]);
            }
            else{
                int t=st.top();
                while(!st.empty() && arr[i]<st.top()){
                    st.pop();
                }
                st.push(t);
            }
        }
        return st.size();
    }

    // FORCED SOLUTION
    // int maxChunksToSorted(vector<int>& arr) {
    //     auto temp=arr;
    //     sort(temp.begin(),temp.end());
    //     ll curr_sum=0;
    //     ll expected_sum=0;
    //     int count=0;
    //     for(int i=0;i<arr.size();i++){
    //         curr_sum += arr[i];
    //         expected_sum += temp[i];
    //         if(curr_sum==expected_sum){
    //             count++;
    //         }
    //     }
    //     return count;
    // }
};