class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
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
                    int sell=prices[index]+dp[index+1][1]-fee;   //buy=1 tells we  can purchase further
                    int not_sell=dp[index+1][0];          //not selling in this pass;
                    profit=max(sell,not_sell);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1]; 
    }
};