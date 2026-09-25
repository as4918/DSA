int maxProfit(int* prices, int pricesSize)
{
    int minPrice = prices[0];
    int profit = 0;

    for(int i = 1; i < pricesSize; i++)
    {
        if(prices[i] - minPrice > profit)
            profit = prices[i] - minPrice;

        if(prices[i] < minPrice)
            minPrice = prices[i];
    }

    return profit;
}