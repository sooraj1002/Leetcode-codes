class Solution {
public:
    string longestPalindrome(string s){
        int n=s.size();
        if(n==1)return s;

        vector<vector<bool>> dp(n,vector<bool>(n,0));
        int max=1;
        int start=0,end=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i+1<n){
                dp[i][i+1]=s[i]==s[i+1];
                if(dp[i][i+1]){
                    max=2;
                    start=i;
                    end=i+1;
                }
            }
        }
        
        for(int k=3;k<=n;k++){                          //shows size of substring
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=1;
                    if(k>max){
                        max=k;
                        start=i;
                        end=j;
                    }
                }
            }
        }
        return s.substr(start,max);


    }

    //RECURSION WITHOUT DP
    // bool isPalindrome(string &s,int start,int end){
    //     while(start<end){
    //         if(s[start] != s[end])
    //             return 0;
    //         start++;
    //         end--;
    //     }
    //     return 1;
    // }
    // string build(string &s,int start,int end){
    //     string ans="";
    //     for(int i=start;i<=end;i++){
    //         ans.push_back(s[i]);
    //     }
    //     return ans;
    // }

    // string solve(string &s,int index,int max_len,string ans){
    //     if(index==s.size())
    //         return "";

    //     for(int j=index;j<s.size();j++){
    //         if(isPalindrome(s,index,j)){
    //             if(j-index+1>max_len){
    //                 ans=build(s,index,j);
    //                 max_len=j-index+1;
    //             }
    //         }
    //     }
    //     auto temp=solve(s,index+1,max_len,ans);
    //     if(temp.size()>ans.size()){
    //         max_len=temp.size();
    //         ans=temp;
    //     }
    //     return ans;
    // }
    // string longestPalindrome(string s) {
    //     return solve(s,0,0,"");
    // }
};