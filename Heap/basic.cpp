#include<iostream>
using namespace std;
class Heap{
    public:
        void Insert(int a[],int n){
            int temp,i=n;
            temp=a[n];
            while(i>1 && temp>a[i/2]){
                a[i]=a[i/2];
                i=i/2;
            }
            a[i]=temp;
        }
        int Delete(int a[],int n){
            int x,i,j;
            x=a[1];
            i=1;
            a[i]=a[n];
            
            j=2*i;
            while(j<=(n-1)){
                if(j+1 <= n-1 && a[j+1] > a[j])
                    j=j+1;
                if(a[i]<a[j]){
                    swap(a[i],a[j]);
                    i=j;
                    j=2*i;
                }
                else break;
            }
            a[n]=x;
            return x;
        }
        void Heapsort();
};
int main(){
    Heap h;
    int A[]={0,10,20,30,25,5,40,35};
    h.Insert(A,1);
    h.Insert(A,2);
    h.Insert(A,3);
    h.Insert(A,4);
    h.Insert(A,5);
    h.Insert(A,6);
    h.Insert(A,7);

    cout<<h.Delete(A,7);
    cout<<endl;
    cout<<h.Delete(A,6);
    cout<<endl;
    for(int i=1;i<8;i++)
        cout<<A[i]<<" ";

    return 0;
}