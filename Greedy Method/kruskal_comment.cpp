#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::iota

using namespace std;

// --- 1. Disjoint Set Union (DSU) Class ---
// Uses Path Compression and Union by Rank for efficient O(alpha(V)) operations.
class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1); // Initialize rank to 1
        // Every node is its own parent initially
        iota(parent.begin(), parent.end(), 0); 
    }

    // FIND operation with Path Compression
    int find(int i) {
        // If i is the root of its tree
        if (parent[i] == i)
            return i;
        // Recursively find parent and compress the path
        return parent[i] = find(parent[i]); 
    }

    // UNION operation by Rank
    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y) {
            // Attach the smaller rank tree under the root of the larger rank tree
            if (rank[root_x] < rank[root_y]) {
                parent[root_x] = root_y;
            } else if (rank[root_x] > rank[root_y]) {
                parent[root_y] = root_x;
            } else {
                // Ranks are the same, make one the parent and increment its rank
                parent[root_y] = root_x;
                rank[root_x]++;
            }
        }
    }
};

// --- 2. Kruskal's MST Implementation ---

/**
 * @brief Computes the Minimum Spanning Tree cost using Kruskal's algorithm.
 * @param V The number of vertices (0 to V-1).
 * @param edges A vector of edges, where each edge is {u, v, weight}.
 * @return The total cost of the MST.
 */
int kruskalsMST(int V, vector<vector<int>>& edges) {
    // Step 1: Sort all edges by weight in non-decreasing order (Greedy choice)
    // Using a lambda function for comparison
    sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
        return a[2] < b[2]; // Compare based on the weight (index 2)
    });

    // Step 2: Initialize DSU structure
    DSU dsu(V);
    int mst_cost = 0;
    int edges_in_mst = 0;
    
    // Step 3: Iterate through sorted edges and select safe edges
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        
        // Optimization: Stop when V-1 edges have been included
        if (edges_in_mst == V - 1) break;

        // Check if u and v are already connected (cycle detection)
        if (dsu.find(u) != dsu.find(v)) {
            // No cycle detected: This is a safe edge (add to MST)
            dsu.unite(u, v);
            mst_cost += weight;
            edges_in_mst++;
        }
    }
    
    // An MST is only possible if all V-1 edges were found.
    return mst_cost;
}

// --- 3. Main Function (Driver Code) ---
int main() {
    /* Example Graph:
     * V = 4 (vertices 0, 1, 2, 3)
     * Edges: (0, 1, 10), (1, 3, 15), (2, 3, 4), (2, 0, 6), (0, 3, 5)
     * MST Edges (Selected by Kruskal's): (2, 3, 4), (0, 3, 5), (0, 1, 10)
     * Total MST Cost: 4 + 5 + 10 = 19
     */
    int V = 4;
    // Edge format: {Source, Destination, Weight}
    vector<vector<int>> edges = {
        {0, 1, 10}, 
        {1, 3, 15}, 
        {2, 3, 4}, 
        {2, 0, 6}, 
        {0, 3, 5}
    };
    
    cout << "Kruskal's Algorithm MST Cost: " << kruskalsMST(V, edges) << endl;
    
    return 0;
}