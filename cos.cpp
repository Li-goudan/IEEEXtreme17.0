#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    int a[t], ans[t];

    for (int i=0; i < t; i++){
        cin >> a[i];
    }

    for (int i = 0; i < t; i++) {
        int n = 1;
        double minCos = abs(cos(a[i]* M_PI / 180.0));
        const int MAX_N = 100000;
        const float e = 10e-9;

        while (n <= MAX_N) {
            double currentCos = abs(cos(n * a[i]* M_PI / 180.0));

            if (currentCos < minCos){
                
                if (abs(currentCos - minCos) < e){
                    n++;
                    continue;
                }
                else{
                    minCos = currentCos;
                    ans[i] = n;
                }
                
            }

            if (abs(currentCos) < e && abs(currentCos - minCos) < e) {
                break;
            }
            n++;
        }
        
    }

    for (const auto &result : ans) {
        cout << result<< ' ';
    }

    return 0;
}