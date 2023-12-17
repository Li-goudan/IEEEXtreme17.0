#include <iostream>
using namespace std;

int v0;
int v1;
int v2;
int v3 = 1;
int v4 = 0;
int v5 = -1;
int v6 = 1;
int v7;
int v8;
int v9;
int v10 = 0;
int v11 = 0;
int v12 = 1;
int v13, v14, v15, v16, v17, v18;

void l0 (), l1 (), l2 (), l3 (), l4 (), l5 (), l6 ();

void l0 (){
    v11 = v11 + v1;
    v10 = v10 + v0;
    v13 = v10;
    v14 = v4;
    v15 = v4;
}

void l1 (){
    v16 = v13 + v13;
    if (v16 <= v1) {
        l2 ();
    }
    else{
        v13 -= v1;
        v14 += v3;
        v15 += v1;
        l1 ();
    }

}

void l2 (){
    if (v13 > v4) {
        l3();
    }
    else{
        v13 = v4 - v13;
    }

}

void l3 (){
    v17 = v4;
    v18 = v3;
}

void l4 (){
    v17 += v13;
    v18 += v3;
    if (v18 <= v6){
        l4 ();
    }
    else 
        v18 = v3;
}

void l5 (){
    v17 -= v9;
    v18 += v3;
    if (v18 <= v12){
        l5 ();
    }
    else{
        if (v17 >= v4){
            l6 ();
        }
        else{
            v5 = v14;
            v6 = v12;
            v7 = v15;
            v8 = v10;
            v9 = v13;
        }

    }

}

void l6 (){
    v12 += v3;
    if (v12 <= v2){
        l0 ();
    }
}

int main(){
    int A, B, C;
    
    cin >> A >> B >> C;

    v0 = A;
    v1 = B;
    v2 = C;
    v7 = -B;
    v8 = A;
    v9 = A + B;

    l0 ();
    l1 ();
    l2 ();
    l3 ();
    l4 ();
    l5 ();
    l6 ();

    cout << v6 << endl;
    return 0;
}