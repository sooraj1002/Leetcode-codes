class Solution {
public:

    // ITERATIVE SOLUTION
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));
        for(int index=prices.size()-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                    int profit;
                    if(buy){
                        int buy= -prices[index]+dp[index+1][0];
                        int not_buy=dp[index+1][1];
                        profit=max(buy,not_buy);
                    }
                    else{
                        int sell=prices[index]+dp[index+2][1];
                        int not_sell=dp[index+1][0];
                        profit=max(sell,not_sell);
                    }
                    dp[index][buy]=profit;
            }
        }
        return dp[0][1];
        
    }

    // RECURSIVE SOLUTION
    // int solve(vector<int> &prices,int index,int buy,int sell,vector<vector<vector<int>>> &dp){
    //     if(index==prices.size())
    //         return 0;
        
    //     if(dp[index][buy][sell] != -1)return dp[index][buy][sell];

    //     if(sell){  //if we have sold the prev day, just skip the given day
    //         return dp[index][buy][sell]=solve(prices,index+1,buy,0,dp);
    //     }
    //     int profit;
    //     if(buy){
    //         int buy= -prices[index]+solve(prices,index+1,0,0,dp);
    //         int not_buy=solve(prices,index+1,1,0,dp);
    //         profit=max(buy,not_buy);
    //     }
    //     else{
    //         int sell=prices[index]+solve(prices,index+1,1,1,dp);
    //         int not_sell=solve(prices,index+1,0,0,dp);
    //         profit=max(sell,not_sell);
    //     }
    //     return dp[index][buy][sell]=profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
    //     return solve(prices,0,1,0,dp);
    // }
};