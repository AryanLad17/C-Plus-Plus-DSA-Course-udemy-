#include<iostream>

using namespace std;
class Knapsack{
    private:
        int obj[7][7];
        int profit[7], weight[7];
        double ratio[7];
    public:
        void get(int n){
            cout<<"Enter the Profit and weight:";
            for(int i=0;i<n;i++){
                cin >> profit[i] >> weight[i];
                ratio[i] = (double)profit[i] / weight[i];
            }
        }
        int Ksack(int n,int m){
            double totalProfit = 0;
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (ratio[i] < ratio[j]) {
                        swap(ratio[i], ratio[j]);
                        swap(profit[i], profit[j]);
                        swap(weight[i], weight[j]);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (weight[i] <= m) {
                    totalProfit += profit[i];
                    m -= weight[i];
                } else {
                    totalProfit += profit[i] * ((double)m / weight[i]);
                    break;
                }
            }
            return totalProfit;
        }
};
int main(){
    Knapsack k;
    int n = 7;
    k.get(n);
    cout << "Maximum Profit = " << k.Ksack(n, 15);
    return 0;
}