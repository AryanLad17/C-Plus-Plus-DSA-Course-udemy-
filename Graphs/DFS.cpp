#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class DFS{
    private:
        vector<int> visited;
    public:
        DFS(int n){
            visited.resize(n,0);
        }
        void dfs(int u,vector<vector<int>> &adj){
            if(visited[u]) return;
            
            cout<<u<<" ";
            visited[u]=1;
            for(int v:adj[u]){
                if(!visited[v])
                    dfs(v,adj);
            }
        }
};
int main() {
    int n = 7;

    vector<vector<int>> adj = {
        {},              // 0 (unused)
        {2, 3},          // 1
        {1, 4},          // 2
        {1, 4, 5},       // 3
        {2, 3, 5, 6},    // 4
        {3, 4},          // 5
        {4}              // 6
    };

    DFS d(n);
    d.dfs(1, adj);

    return 0;
}