#include<iostream>
using namespace std;

class LowerTriCol {
private:
    int n;
    int *A;

public:
    LowerTriCol(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }

    void set(int i, int j, int x) {
        if(i >= j)
            A[(n-j+1)*(j-1) + (i-j)] = x;
    }

    int get(int i, int j) {
        if(i >= j)
            return A[(n-j+1)*(j-1) + (i-j)];
        return 0;
    }

    void display() {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i >= j)
                    cout << A[(n-j+1)*(j-1) + (i-j)] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }

    ~LowerTriCol() {
        delete []A;
    }
};

int main() {
    int n = 3;
    LowerTriCol m(n);

    m.set(1,1,1);
    m.set(2,1,2);
    m.set(2,2,3);
    m.set(3,1,4);
    m.set(3,2,5);
    m.set(3,3,6);

    m.display();
    return 0;
}
