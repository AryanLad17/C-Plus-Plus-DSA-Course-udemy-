#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class DFS{
    private:
        int visited[10];
        stack<int> s;
    public:
        DFS(){
            for (int i = 0; i < 10; i++)
            visited[i] = 0;
        }
        void DFS1(int u,int a[][7],int n){
            if(visited[u]==0){
                cout<<u<<" ";
                visited[u]=1;
                for(int v=0;v<n;v++){
                    if(a[u][v]==1 && visited[v]==0)
                        DFS1(v,a,n);
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
    DFS d;
    d.DFS1(1,a,7);
    return 0;
}