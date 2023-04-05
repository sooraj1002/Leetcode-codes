class Solution {
public:
    
    // TABULATION
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int transactions=1;transactions<=2;transactions++){
                    int profit;
                    if(buy){ //if we are allowed to buy
                        int buy= -1*prices[index]+dp[index+1][0][transactions];   //bought something
                        int not_buy=dp[index+1][1][transactions];  //not buying anything
                        profit=max(buy,not_buy);
                    }
                    else{  //we are not allowed to buy, so we can only sell
                        int sell=prices[index]+dp[index+1][1][transactions-1];   //buy=1 tells we  can purchase further
                        int not_sell=dp[index+1][0][transactions];          //not selling in this pass;
                        profit=max(sell,not_sell);
                    }
                    dp[index][buy][transactions]=profit;
                }
            }
        }
        return dp[0][1][2];
    }

    // RECURSIVE SOLUTION
    // int solve(vector<int> &prices,int index,int buy,vector<vector<vector<int>>> &dp,int transactions){
    //     if(index==prices.size())
    //         return 0;
    //     if(transactions==0) return 0;

    //     if(dp[index][buy][transactions] != -1)return dp[index][buy][transactions];
        
    //     int profit;
    //     if(buy){ //if we are allowed to buy
    //         int buy= -1*prices[index]+solve(prices,index+1,0,dp,transactions);   //bought something
    //         int not_buy=solve(prices,index+1,1,dp,transactions);  //not buying anything
    //         profit=max(buy,not_buy);
    //     }
    //     else{  //we are not allowed to buy, so we can only sell
    //         int sell=prices[index]+solve(prices,index+1,1,dp,transactions-1);   //buy=1 tells we  can purchase further
    //         int not_sell=solve(prices,index+1,0,dp,transactions);          //not selling in this pass;
    //         profit=max(sell,not_sell);
    //     }
    //     return dp[index][buy][transactions]=profit; 
    // }

    // int maxProfit(vector<int>& prices) {
    //     vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
    //     return solve(prices,0,1,dp,2);
    // }
};