// PROBLEM STATEMENT: 
//     Find the minimum no. of steps to reach the nth step given 
//     that you can only jump 1 or 3 steps at a time.
// EXAMPLE:
//     Min. no. of steps to reach the 1st step = 1 (1)
//     Min. no. of steps to reach the 2nd step = 2 (1 + 1)  
//     Min. no. of steps to reach the 3rd step = 1 (3)
//     Min. no. of steps to reach the 4th step = 2 (3 + 1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Global vector to keep track of min. steps to reach nth step.
vector<int> min_steps{0, 1, 2, 1};

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // Your code goes here.
    int q, u_input;
    vector<int> queries;
    cin >> q;
    for(int i=0; i<q; i++) {
        cin >> u_input;
        queries.push_back(u_input);
    }
    // Since there are multiple queries, we will find the maximum
    // value of n (i.e., the goal step number). Then we will find
    // the min. no. of steps required to reach goal state- 1 to n.
    int q_max = *max_element(queries.begin(), queries.end());
    for(int i=4; i<=q_max; i++) {
        // We use a dynamic programming approach where we use
        // previously store information to count the min. of steps
        // to reach current goal state.
        int min_step = 1 + min(min_steps[i-1], min_steps[i-3]);
        min_steps.push_back(min_step);
    }
    // Print the results for the different queries.
    for(const auto &x: queries) {
        cout << min_steps[x] << endl;
    }
    
    return 0;
}