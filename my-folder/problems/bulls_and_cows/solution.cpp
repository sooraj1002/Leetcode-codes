class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> mp,mp1;
        int same=0;
        int available=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                same++;
            }
            else{
                mp[secret[i]]++;
                mp1[guess[i]]++;
            }
        }
        // for(auto i:mp){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        // cout<<"mp2"<<endl;
        // for(auto i:mp1){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        for(auto i:mp){
            int key=i.first;
            if(mp1.find(key) != mp1.end() ){
                // cout<<"key "<<key<<endl;
                // cout<<"mp "<<mp[key]<<" mp1 "<<mp1[key]<<endl;
                // int n=mp1[key]-mp[key];
                // // if(n<0)
                //     // available += mp1[key];
                // // else
                //     // available += mp[key];
                available += min(mp1[key],mp[key]);
            }
        }
        string ans= to_string(same)+"A"+to_string(available)+"B";
        return ans;
    }
};