#include <iostream>
#include <cmath>
using namespace std;

bool valid(int x[], int k, int l){
    for(int i = 1; i < k; i++){
        if(x[i] == l || abs(i - k) == abs(x[i] - l))
            return false;
    }
    return true;
}

int NQueen(int x[], int n, int k){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(valid(x, k, i)){
            x[k] = i;
            if(k == n){
                for(int j = 1; j <= n; j++){
                    cout << x[j] << (j == n ? '\n' : ' ');
                }
                count++;
            } else {
                count += NQueen(x, n, k + 1);
            }
        }
    }
    return count;
}

int main(){
    int n = 4;
    // To read n from input, uncomment below lines:
    // cout << "Enter n: ";
    // if(!(cin >> n)) return 0;

    int *x = new int[n + 1];
    int solutions = NQueen(x, n, 1);
    cout << "Total solutions: " << solutions << "\n";
    delete[] x;
    return 0;
}