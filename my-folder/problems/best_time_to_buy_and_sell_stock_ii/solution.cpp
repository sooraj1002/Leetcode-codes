class Solution {
public:

        int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        int n=prices.size();
        dp[n][0]=0;
        dp[n][1]=0;

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    int buy= -1*prices[index]+dp[index+1][0];   //bought something
                    int not_buy=dp[index+1][1];  //not buying anything
                    profit=max(buy,not_buy);
                }
                else{  //we are not allowed to buy, so we can only sell
                    int sell=prices[index]+dp[index+1][1];   //buy=1 tells we  can purchase further
                    int not_sell=dp[index+1][0];          //not selling in this pass;
                    profit=max(sell,not_sell);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }

//     RECURSIVE SOLUTION
//     int solve(vector<int> &prices,int index,int buy,vector<vector<int>> &dp){
//         if(index==prices.size())
//             return 0;
//         if(dp[index][buy] != -1)return dp[index][buy];
//         int profit;
//         if(buy){ //if we are allowed to buy
//             int buy= -1*prices[index]+solve(prices,index+1,0,dp);   //bought something
//             int not_buy=solve(prices,index+1,1,dp);  //not buying anything
//             profit=max(buy,not_buy);
//         }
//         else{  //we are not allowed to buy, so we can only sell
//             int sell=prices[index]+solve(prices,index+1,1,dp);   //buy=1 tells we  can purchase further
//             int not_sell=solve(prices,index+1,0,dp);          //not selling in this pass;
//             profit=max(sell,not_sell);
//         }

//         return dp[index][buy]=profit;
        
//     }
//     int maxProfit(vector<int>& prices) {
//         vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
//         return solve(prices,0,1,dp);
//     }
};