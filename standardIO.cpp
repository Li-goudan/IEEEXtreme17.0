#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

const int MOD = 998244353;  // 定义模数

// 计算2的幂
int powerOf2(int exp) {
    return 1 << exp;  // 左移运算符表示计算2的exp次幂
}

// 计算阶乘
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// 计算排列组合情况数
int calculateCombinations(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// 递归生成包含M个字符串中字符，长度为N的所有字符串
void generateStrings(const vector<string>& strings, int N, string& current, int& count) {
    if (current.size() == static_cast<size_t>(N)) {
        // 如果当前字符串长度为N，增加计数器
        count++;
    } else {
        for (const string& s : strings) {
            current.push_back(s[current.size()]);
            generateStrings(strings, N, current, count);
            current.pop_back();
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;  // 输入长度 N 和字符串个数 M

    // // 计算排列组合情况数
    // int combinations = calculateCombinations(26, N);

    map<string, int> occurrences;  // 用于存储每个字符串的出现次数
    vector<string> strings(M);

    // 输入 M 个字符串并计算出现次数
    for (int i = 0; i < M; ++i) {
        string s;
        cin >> s;
        occurrences[s]++;
    }
    for (int i = 0; i < M; ++i) {
        cin >> strings[i];
    }

    // int count = 0;
    // string current;

    // generateStrings(strings, N, current, count);

    double kAll = pow(26, N);

    int totalPower = 0;
    int result = 0;

    // 计算每个字符串power并求和
    for (const auto& entry : occurrences) {
        totalPower = (totalPower + powerOf2(entry.second)) % MOD;
        result = pow(2, totalPower);
    }

    // // 计算最终字符串power
    // int result = powerOf2(N) * totalPower % MOD;

    cout << result << endl;  // 输出结果

    return 0;
}
