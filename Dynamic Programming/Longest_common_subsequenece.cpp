#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LCS(char a[], char b[], int i, int j) {
    if (i == 0 || j == 0)
        return 0;
    if (a[i - 1] == b[j - 1])
        return 1 + LCS(a, b, i - 1, j - 1);
    else
        return max(LCS(a, b, i - 1, j), LCS(a, b, i, j - 1));
}

int LCS1(char a[], char b[], int i, int j, vector<vector<int>>& l) {         //using memoiztion
    if (i == 0 || j == 0) {
        return 0;
    }
    if (l[i][j] != -1) {
        return l[i][j];
    }
    if (a[i - 1] == b[j - 1]) {
        l[i][j] = 1 + LCS1(a, b, i - 1, j - 1, l);
    } else {
        l[i][j] = max(LCS1(a, b, i - 1, j, l), LCS1(a, b, i, j - 1, l));
    }
    return l[i][j];
}
int LCS2(char a[], char b[], int n, int m) {                 //using tabulation
    int l[n+1][m+1];
    for(int i=0;i<=m;i++)l[0][i]=0;
    for(int j=0;j<=n;j++)l[j][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])
                l[i][j]=1+l[i-1][j-1];
            else
                l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
    }
    return l[n][m];
}
int main() {
    char a[] = {'a', 'c', 'e'};
    char b[] = {'a', 'b', 'c', 'd', 'e'};
    int i = sizeof(a) / sizeof(a[0]);
    int j = sizeof(b) / sizeof(b[0]);

    vector<vector<int>> l(i + 1, vector<int>(j + 1, -1));

    cout << LCS(a, b, i, j) << endl;
    cout << LCS1(a, b, i, j, l) << endl;
    cout << LCS2(a, b, i, j) << endl;

    return 0;
}