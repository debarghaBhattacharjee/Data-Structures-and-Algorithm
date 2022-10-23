# PROBLEM STATEMENT:
# Assuming that you are provided the stock prices for the next 
# n days, find the maximum profit you can make from the stock 
# market if you are allowed to make only one buy and one sell 
# in that order. You can also buy and sell a stock on the same 
# day but you won't make any profit in such a scenario. Also, 
# you cannot make a 'sell' before a 'buy'.

# EXAMPLE 1:
# Let n = 10
# prices = [100, 110, 120, 112, 105, 115, 117, 111, 121, 122]
# max profit = 22

# EXAMPLE 2:
# Let n = 5
# prices = [100, 99, 98, 97, 96]
# max profit = 0


def get_max_profit(prices: list()) -> int:
    """
    Method to get max profit given a list of prices
    for next k days.
    """
    n = len(prices)
    INT_MAX = float("inf")
    INT_MIN = -INT_MAX
    
    # Get the minimum prefix stock price up to current day. 
    prefix_mins = [INT_MAX] * n
    prefix_mins[0] = prices[0]
    for i in range(1, n):
        prefix_mins[i] = min(prefix_mins[i-1], prices[i])
    
    # Get the maximum suffix stock price from current day.
    suffix_maxs = [INT_MIN] * n
    suffix_maxs[n - 1] = prices[n - 1]
    for i in range(n-2, -1, -1):
        suffix_maxs[i] = max(suffix_maxs[i+1], prices[i])
    
    # Get the maximum profit possible that can be made 
    # at each day.
    max_profits = [
        suffix_max - prefix_min
        for (prefix_min, suffix_max) in zip(prefix_mins, suffix_maxs)
    ]
    max_profit = INT_MIN
    max_profit = max(max_profit, max(max_profits))
    return max_profit

    
# Driver code
if __name__ == "__main__":
    prices = str(input())
    prices = [int(price) for price in prices.split(' ')]
    max_profit = get_max_profit(prices)
    print(max_profit)