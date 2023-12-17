#include <iostream>
using namespace std;

long long myFunction(long long A, long long B, long long C) {
    long long v0 = A;
    long long v1 = B;
    long long v2 = C;
    long long v3 = 1;
    long long v4 = v3 - v3;
    long long v5 = v4 - v3;
    long long v6 = v3;

    long long v7 = v4 - v1;
    long long v8 = v0;
    long long v9 = v0;
    v9 = v0 + v1;
    long long v10 = v4;
    long long v11 = v4;
    long long v12 = v3;

l0:
    v11 = v11 + v1;
    v10 = v10 + v0;
    long long v13 = v10;
    long long v14 = v4;
    long long v15 = v4;

l1:
    long long v16 = v13 + v13;
    if (v16 <= v1) {
        goto l2;
    }
    v13 = v13 - v1;
    v14 = v14 + v3;
    v15 = v15 + v1;
    goto l1;

l2:
    if (v13 > v4) {
        goto l3;
    }
    v13 = v4 - v13;

l3:
    long long v17 = v4;
    long long v18 = v3;

l4:
    v17 = v17 + v13;
    v18 = v18 + v3;

    if (v18 <= v6) {
        goto l4;
    }
    v18 = v3;

l5:
    v17 = v17 - v9;
    v18 = v18 + v3;
    
    if (v18 <= v12) {
        goto l5;
    }
    if (v17 >= v4) {
        goto l6;
    }
    v5 = v14;
    v6 = v12;
    v7 = v15;
    v8 = v10;
    v9 = v13;

l6:
    v12 = v12 + v3;
    if (v12 <= v2){
        goto l0;
    }
    return v6;
}

int main() {
    long long T, A, B, C;
    cin >> T;
    long long ans[T];

    for (long long i=0; i < T; i++){
        cin >> A >> B >> C;
        ans[i] = myFunction(A, B, C);
    }

    for (const auto &result : ans) {
        cout << result << endl;
    }

    return 0;
}
