class Solution {
public:

    // //ITERATIVE SOLUTION
    bool isMatch(string s, string p){
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0]=1;
        for(int i=1;i<=s.size();i++)
            dp[i][0]=false;

        for(int i=1;i<=p.size();i++){
            int flag=1;
            for(int k=0;k<i;k++){
                if(p[k] != '*'){
                    flag=0;
                    break;
                }
            }
            dp[0][i]=flag;
        }

        for(int ind1=1;ind1<=s.size();ind1++){
            for(int ind2=1;ind2<=p.size();ind2++){
                    if(p[ind2-1]==s[ind1-1] || p[ind2-1]=='?') dp[ind1][ind2]=dp[ind1-1][ind2-1];
        
                    else if(p[ind2-1]=='*') dp[ind1][ind2]=dp[ind1][ind2-1] || dp[ind1-1][ind2];
                    else dp[ind1][ind2]=false;
            }
        }
        return dp[s.size()][p.size()];
    }

    //RECURSIVE SOLUTION
    // bool solve(string &s,string&p,int ind1,int ind2,vector<vector<int>> &dp){
    //     if(ind2==0 && ind1==0) return true;
    //     if(ind2==0 && ind1>0) return false;
    //     if(ind1==0 && ind2>0){  
    //         for(int i=0;i<ind2;i++){
    //             if(p[i] != '*')return false;
    //         }
    //         return true;
    //     }

    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    //     if(p[ind2-1]==s[ind1-1] || p[ind2-1]=='?')return dp[ind1][ind2]=solve(s,p,ind1-1,ind2-1,dp);
        
    //     if(p[ind2-1]=='*') return dp[ind1][ind2]=solve(s,p,ind1,ind2-1,dp) || solve(s,p,ind1-1,ind2,dp);      //to generate all cases for * with len=0,1,2,3....

    //     return dp[ind1][ind2]=false;
    // }


    // bool isMatch(string s, string p){
    //     vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
    //     return solve(s,p,s.size(),p.size(),dp);
    // }

    // WRONG SOLUTION/APPROACH
    // bool solve(string &s1,string &s2,int ind1,int ind2,bool flag){
    //     if(ind2<0 && (flag==1 || ind1<0))return true;
    //     else if(ind2<0 && ind1>=0) return false;
    //     if(ind1<0)return false;
        
    //     if(s2[ind2]=='*') return solve(s1,s2,ind1,ind2-1,1);
    //     if(s2[ind2]=='?') return solve(s1,s2,ind1-1,ind2-1,flag);
    //     if(s1[ind1]==s2[ind2]) {
    //         return solve(s1,s2,ind1-1,ind2-1,0) || solve(s1,s2,ind1-1,ind2-1,1);
    //     }
    //     return solve(s1,s2,ind1-1,ind2,flag);
    // }   

    // bool isMatch(string s, string p) {
    //     int n1=s.size();
    //     int n2=p.size();
    //     return solve(s,p,n1-1,n2-1,0);
    // }
};