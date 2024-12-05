#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;  // Maximum number of nodes
vector<int> adj[N], rev_adj[N];  // Adjacency lists for original and reversed graph
bool visited[N];
stack<int> finish_stack;

void input() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // Add the edge in the original graph
        rev_adj[v].push_back(u);  // Add the reversed edge in the reverse graph
    }
}

// DFS to process the original graph and push nodes to finish_stack
void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    finish_stack.push(u);  // Push to stack when finishing DFS for this node
}

// DFS on the reversed graph to mark the SCCs
void dfs2(int u) {
    visited[u] = true;
    for (int v : rev_adj[u]) {
        if (!visited[v]) {
            dfs2(v);
        }
    }
}

int findSCCs(int n) {
    fill(visited, visited + n + 1, false);  // Reset visited array

    // Step 1: Perform DFS on the original graph and push nodes to finish_stack
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    // Step 2: Reverse DFS based on the finish order from the stack
    fill(visited, visited + n + 1, false);  // Reset visited array for second DFS

    int scc_count = 0;
    while (!finish_stack.empty()) {
        int node = finish_stack.top();
        finish_stack.pop();
        if (!visited[node]) {
            // Start a DFS for a new SCC
            dfs2(node);
            scc_count++;
        }
    }

    return scc_count;
}

int main() {
    input();
    int n;
    cin >> n;

    int result = findSCCs(n);
    cout << result << endl;
    return 0;
}
