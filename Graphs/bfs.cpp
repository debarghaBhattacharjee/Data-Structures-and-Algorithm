// PROBLEM STATEMENT: A simple BFS implementation in C++.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Visited vector to keep track of whether a 
// give vertex (or node) has been visited or not.
vector<bool> visited;
// Vector-based template to represent the graph as
// a adjacency list.
vector<vector<int>> graph;
// Method to add new edge to the existing graph.
void add_edge(int u, int v) {
    graph[u].push_back(v);
    return;
}
void bfs(int s) {
    // Use queue to traverse through the graph.
    queue<int> q;
    q.push(s);
    visited[s] = true;

    // Start the traversal and stop when the queue
    // is empty.
    while(!q.empty()) {
        int f = q.front();
        cout << f << " -> ";
        q.pop();

        for(auto i=graph[f].begin(); i!=graph[f].end(); i++) {
            if(visited[*i] == false) {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
    // 'END' denotes the end of the traversal.
    cout << "END" << endl;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // Your code goes here.
    int num_vertices, num_edges;

    cin >> num_vertices >> num_edges;
    // Initialize visited vector with false for
    // every node.
    visited.assign(num_vertices, false);
    // Initialize an empty vector for every node.
    graph.assign(num_vertices, vector<int>());

    // Insert edges and create graph from user input.
    int u, v;  // u- Start node, v- End node
    for(int i=0; i<num_edges; i++) {
        cin >> u >> v;
        add_edge(u, v);
    }

    // Traverse through the graph using BFS method.
    for(int s=0; s<num_vertices; s++) {
        // If the visited for the given node is False,
        // it means that node hasn't been visited yet.
        // Therefore, we traverse through this node and
        // all its immediate neighbours.
        if(!visited[s]) {
            bfs(s);
        }
    }
    
    return 0;
}