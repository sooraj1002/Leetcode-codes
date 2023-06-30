class Solution {
public:
    
    void solve(string digits,vector<string> &ans,map<int,vector<char>> &mp,int index,string op){
        if(index>=digits.size()){
            ans.push_back(op);
            return;
        }
        string temp;
        
        int digit=int(digits[index]-'0');
        for(auto j:mp[digit]){
            op.push_back(j);
            solve(digits,ans,mp,index+1,op);
            op.pop_back();
        }
        
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<int,vector<char>> mp;
        mp.insert({2,{'a','b','c'}});
        mp.insert({3,{'d','e','f'}});
        mp.insert({4,{'g','h','i'}});
        mp.insert({5,{'j','k','l'}});
        mp.insert({6,{'m','n','o'}});
        mp.insert({7,{'p','q','r','s'}});
        mp.insert({8,{'t','u','v'}});
        mp.insert({9,{'w','x','y','z'}});
                                    
        solve(digits,ans,mp,0,"");
        if(digits.size()==0){
            return {};
        }
        return ans;
    }
};