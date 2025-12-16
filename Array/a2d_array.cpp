#include<iostream>
using namespace std;
int main(){
    int a[3][4]={{1,2,3,1},{4,5,6,4},{7,8,9,7}};

    int *b[3];
    b[0]=new int[4];
    b[1]=new int[4];
    b[2]=new int[4];

    int **c;
    c=new int*[3];
    c[0]=new int[4];
    c[1]=new int[4];
    c[2]=new int[4];

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=0; i<3; i++){
        delete[] c[i];   // delete each row
    }
    delete[] c;           // delete array of pointers
    for(int i=0; i<3; i++){
        delete[] b[i];
    }

    return 0;
}