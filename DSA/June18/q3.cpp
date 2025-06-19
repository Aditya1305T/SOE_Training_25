class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // if(n == 1) return 0;
        int i = 0, j = 1;
        int profit = 0;
        while(j < n){
            if(prices[i] < prices[j])
                profit = max(profit, prices[j++] - prices[i]);
            
            else{
                i = j;
                j++;
            }
            
        }
        return profit;
    }
};