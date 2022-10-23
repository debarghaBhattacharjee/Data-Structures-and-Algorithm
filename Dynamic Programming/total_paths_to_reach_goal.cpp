// PROBLEM STATEMENT: 
//     Find the total no. of paths to reach the nth step given 
//     that you can only jump 1 or 3 steps at a time.
// EXAMPLE:
//     Min. no. of steps to reach the 1st step = 1 (1)
//     Min. no. of steps to reach the 2nd step = 1 (1 + 1)  
//     Min. no. of steps to reach the 3rd step = 2 (1 + 1 + 1, 3)
//     Min. no. of steps to reach the 4th step = 3 (1 + 1 + 1, 1 + 3, 3 + 1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Global vector to keep track of total no. of paths to reach goal 
// state (i.e., the nth step).
vector<int> total_paths{0, 1, 1, 2};

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
    // the total no. of paths required to reach goal state- 1 to n.
    int q_max = *max_element(queries.begin(), queries.end());
    for(int i=4; i<=q_max; i++) {
        // We use a dynamic programming approach where we use
        // previously store information to count the total no. 
        // of paths to reach current goal state.
        int total_path = total_paths[i-1] + total_paths[i-3];
        total_paths.push_back(total_path);
    }
    // Print the results for the different queries.
    for(const auto &x: queries) {
        cout << total_paths[x] << endl;
    }

    return 0;
}