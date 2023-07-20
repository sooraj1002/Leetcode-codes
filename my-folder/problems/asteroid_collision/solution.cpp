class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto asteroid:asteroids){
            if(asteroid>0 || st.empty()){
                st.push(asteroid);
            }
            else{
                while(!st.empty() && st.top() >0 && st.top() < abs(asteroid)){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(asteroid) ){
                    st.pop();
                }
                else if(st.empty() || st.top()<0){
                    st.push(asteroid);
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};