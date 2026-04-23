#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BFS {
private:
    vector<int> visited;

public:
    BFS(int n) {
        visited.resize(n, 0);
    }

    void traverse(int start, vector<vector<int>>& adj) {
        if (start < 0 || start >= adj.size())
            return;

        queue<int> q;

        visited[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
    }
};

int main() {
    int n = 7;

    vector<vector<int>> adj = {
        {},         // 0 (unused to match your original graph)
        {2, 3},     // 1
        {1, 4},     // 2
        {1, 4, 5},  // 3
        {2, 3, 5, 6}, // 4
        {3, 4},     // 5
        {4}         // 6
    };

    BFS b(n);
    b.traverse(1, adj);

    return 0;
}