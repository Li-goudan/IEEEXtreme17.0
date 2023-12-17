#include <iostream>
#include <string>
#include <set>
#include <vector>

// 将字符串转换为小写
void toLowerCase(std::string& s) {
    for (auto& x : s) {
        x = tolower(x);
    }
}

// 将字符串分词为单词向量
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;

    while ((end = s.find(' ', start)) != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(s.substr(start));
    return tokens;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::cin.ignore(); // 读取n和m后消耗换行符

    std::vector<std::string> ns(n), ms(m);

    // 输入ns中的字符串并将其转换为小写
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, ns[i]);
        toLowerCase(ns[i]);
    }

    std::cin.ignore(); // 读取ns中最后一个字符串后消耗换行符

    // 输入ms中的字符串并将其转换为小写，提取每个字符串的最后一个单词
    for (int i = 0; i < m; ++i) {
        std::getline(std::cin, ms[i]);
        toLowerCase(ms[i]);
        ms[i] = ms[i].substr(ms[i].find_last_of(' ') + 1);
    }

    std::vector<std::set<std::string>> ps(n);

    // 将ns中每个字符串分词并插入集合ps中
    for (int i = 0; i < n; ++i) {
        const auto& tokens = tokenize(ns[i]);
        ps[i].insert(tokens.begin(), tokens.end());
    }

    std::vector<int> index(m, -1);
    std::vector<int> indexCount(101, 0);
    std::vector<char> out(101, -1);

    char outputChar = 'A';

    // 查找ms中每个单词在ns中第一次出现的索引
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ps[j].count(ms[i]) > 0) {
                index[i] = j;
                break;
            }
        }
    }

    // 计算每个索引在index数组中出现的次数
    for (int i = 0; i < m; ++i) {
        if (index[i] != -1)
            ++indexCount[index[i]];
    }

    // 根据条件输出结果
    for (int i = 0; i < m; ++i) {
        if (index[i] == -1 || indexCount[index[i]] <= 1)
            std::cout << 'X';
        else {
            if (out[index[i]] == -1) {
                out[index[i]] = outputChar++;
                if (outputChar == 'X')
                    ++outputChar;
            }
            std::cout << out[index[i]];
        }
    }

    return 0;
}
