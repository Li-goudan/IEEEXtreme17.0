#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

void calculateCombinations(int n, vector<long long>& dp) {
        for (int j = 0; j <= n; ++j) {
        if (j == 0){
            dp[j] = 1;
        }
        else{
            if (j <= (n/2)){
                dp[j] = (dp[j-1] * (n-j+1) / j) % MOD;
            }
            else{
                dp[j] = dp[n-j];
            }
            
        }
}
}


int main() {
    int k, n;

    cin >> k >> n;

    int num = 1 << k;  // 使用位运算计算 2^k
    vector<long long> a(num, 0);

    // 使用一维数组保存组合数计算的中间结果
    vector<long long> dp(n + 1, 0);

    calculateCombinations(n, dp);

    for (int j = 0; j <= n; ++j) {
        // if (j == 0){
        //     dp[j] = 1;
        // }
        // else{
        //     dp[j] = (dp[j-1] * (n-j+1) / j) % MOD;
        // }
        a[j % num] = (a[j % num] + dp[j]) % MOD;
    }

    for (const auto &result : a) {
        cout << result<< ' ';
    }

    return 0;
}