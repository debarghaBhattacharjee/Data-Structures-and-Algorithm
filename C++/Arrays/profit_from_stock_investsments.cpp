// PROBLEM STATEMENT:
// Assuming that you are provided the stock prices for the next 
// n days, find the maximum profit you can make from the stock 
// market if you are allowed to make only one buy and one sell 
// in that order. You can also buy and sell a stock on the same 
// day but you won't make any profit in such a scenario. Also, 
// you cannot make a 'sell' before a 'buy'.

// EXAMPLE 1:
// Let n = 10
// prices = [100, 110, 120, 112, 105, 115, 117, 111, 121, 122]
// max profit = 22

// EXAMPLE 2:
// Let n = 5
// prices = [100, 99, 98, 97, 96]
// max profit = 0


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// Function to get max profit given a list of prices
// for next k days.
int get_max_profit(const vector<int> &prices) {

    int n = prices.size();
    
    // Get the minimum prefix stock price up to current day. 
    vector<int> prefix_mins(n, INT_MAX);
    prefix_mins[0] = prices[0];
    for (int i=1; i<n; i++) {
        prefix_mins[i] = min(prefix_mins[i-1], prices[i]);
    }
    
    // Get the maximum suffix stock price from current day.
    vector<int> suffix_maxs(n, INT_MIN);
    suffix_maxs[n - 1] = prices[n - 1];
    for (int i=n-2; i>-1; i--) {
        suffix_maxs[i] = max(suffix_maxs[i+1], prices[i]);
    }
    
    // Get the maximum profit possible that can be made 
    // at each day.
    vector<int> max_profits(n, INT_MIN);
    for (int i=0; i<n; i++) {
        int suffix_max = suffix_maxs[i];
        int prefix_min = prefix_mins[i];
        max_profits.push_back(suffix_max - prefix_min);
    }
    int max_profit = INT_MIN;
    max_profit = max(
        max_profit, 
        *max_element(max_profits.begin(), max_profits.end())
    );
    return max_profit;
}


// Driver code
int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // Your code goes here.
    int n, u_input;
    vector<int> prices(n, INT_MIN);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> u_input;
        prices[i] = u_input;
    }
    int max_profit = get_max_profit(prices);
    cout << max_profit << endl;
    
    return 0;
}