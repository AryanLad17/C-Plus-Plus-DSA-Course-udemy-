#include <iostream>
#include <queue>
using namespace std;
class BSF
{
private:
    int visited[10];
    queue<int> q;

public:
    BSF()
    {
        for (int i = 0; i < 10; i++)
            visited[i] = 0;
    }
    void BFS(int i, int a[][7], int n)
    {
        cout << i<<" ";
        visited[i] = 1;
        q.push(i);
        int u;
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            for (int v = 0; v < n; v++)
            {
                if (a[u][v] == 1 && visited[v] == 0)
                {
                    cout << v<<" ";
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
    }
};
int main()
{
    int a[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    int n = 7;
    BSF b;
    b.BFS(1, a, 7);
    return 0;
}