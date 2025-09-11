class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        if (n <= 1)
            return 0;

        bool isHolding = false;
        int i = 0;
        int j = 1;
        int buyingprice = 0;
        int profit = 0;

        if (n == 2 && prices[j] > prices[i])
        {
            return prices[j] - prices[i];
        }
        for (int k = 0; k < n - 1; k++)
        {
            if (isHolding)
            {
                if (prices[j] < prices[i])
                {
                    profit = profit + prices[i] - buyingprice;
                    isHolding = false;
                }
                else if (j == n - 1 & prices[j] > buyingprice)
                {
                    profit = profit + prices[j] - buyingprice;
                    isHolding = false;
                    return profit;
                }
            }
            else
            {
                if (prices[j] > prices[i])
                {
                    buyingprice = prices[i];
                    isHolding = true;
                    if (j == n - 1)
                    {
                        profit = profit + prices[j] - buyingprice;
                        isHolding = false;
                        return profit;
                    }
                }
            }
            i++;
            j++;
        }

        return profit;
    }
};