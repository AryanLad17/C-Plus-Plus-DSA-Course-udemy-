#include<iostream>
using namespace std;
struct Element{
    int i;
    int j;
    int x;
};
struct spare{
    int n;
    int m;
    int num;
    struct Element *e;
};
void create(struct spare *s){
    cout<<"Enter the rows and columns: ";
    cin>>s->n>>s->m;
    cout<<"Enter the number of non zero element:";
    cin>>s->num;
    s->e=new Element[s->num];
    cout<<"Enter the element:";
    for(int a=0;a<s->num;a++){
        cin>>s->e[a].i>>s->e[a].j>>s->e[a].x;
    }
}
void display(struct spare s){
    int k=0;
    for(int i = 1; i <= s.n; i++){
        for(int j = 1; j <= s.m; j++){
            if(k < s.num && i == s.e[k].i && j == s.e[k].j)
                cout << s.e[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

}
struct spare* add(struct spare *s1, struct spare *s2) {
    int i = 0, j = 0, k = 0;

    if(s1->n != s2->n || s1->m != s2->m)
        return nullptr;

    struct spare* sum = new spare;
    sum->n = s1->n;
    sum->m = s1->m;
    sum->e = new Element[s1->num + s2->num];

    while(i < s1->num && j < s2->num) {
        if(s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        else if(s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else {
            if(s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            else if(s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            else {
                sum->e[k] = s1->e[i];
                sum->e[k].x = s1->e[i].x + s2->e[j].x;
                i++; j++; k++;
            }
        }
    }

    for(; i < s1->num; i++)
        sum->e[k++] = s1->e[i];

    for(; j < s2->num; j++)
        sum->e[k++] = s2->e[j];

    sum->num = k;
    return sum;
}

int main() {
    spare s;
    create(&s);
    display(s);

    spare s1;
    create(&s1);
    display(s1);

    spare *sum = add(&s, &s1);
    display(*sum);        // FIX 1

    delete[] s.e;
    delete[] s1.e;
    delete[] sum->e;      // FIX 2
    delete sum;           // free struct itself

    return 0;
}
