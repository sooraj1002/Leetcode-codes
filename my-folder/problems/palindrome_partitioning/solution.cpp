class Solution {
public:
    bool isPalindrome(string s){
        int start=0;
        int end=s.size()-1;
        while(start<=end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void solve(string s,vector<vector<string>> &ans,vector<string> &temp,int index){
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }
        // cout<<"hiiii"<<endl;
        for(int i=index;i<s.size();i++){
            string t=s.substr(index,i-index+1);
            // cout<<t<<" ";
            if(isPalindrome(t)){
                temp.push_back(t);
                solve(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,ans,temp,0);
        return ans;
    }
};