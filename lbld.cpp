#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

void inputWords(int size, std::vector<std::string> &words) {
    for (int i = 0; i < size; ++i) {
        std::string word;
        std::cin >> word;
        words[i] = word;
    }
}

void processWords(const std::vector<std::string> &words, int minLength,
                  std::unordered_map<std::string, std::vector<std::string>> &prefixMap,
                  std::unordered_map<std::string, std::vector<std::string>> &suffixMap) {
    for (const std::string &word : words) {
        if (word.length() >= minLength) {
            std::string prefix = word.substr(0, minLength);
            std::string suffix = word.substr(word.size() - minLength);
            prefixMap[prefix].push_back(word);
            suffixMap[suffix].push_back(word);
        }
    }
}

int main() {
    int numWordsInDictionary, numBlends;
    std::cin >> numWordsInDictionary >> numBlends;

    std::vector<std::string> dictionary(numWordsInDictionary);
    std::vector<std::string> blends(numBlends);

    std::unordered_map<std::string, std::vector<std::string>> commonPrefixMap;
    commonPrefixMap.reserve(numWordsInDictionary);

    std::unordered_map<std::string, std::vector<std::string>> commonSuffixMap;
    commonSuffixMap.reserve(numWordsInDictionary);

    inputWords(numWordsInDictionary, dictionary);

    inputWords(numBlends, blends);

    const int minLength = 3;


	processWords(dictionary, minLength, commonPrefixMap, commonSuffixMap);

    for (const std::string& word : blends) {
        if (word.length() < minLength + 2) {
            std::cout << "none" << std::endl;
            continue;
        }

        std::string prefix = word.substr(0, minLength);
        std::string suffix = word.substr(word.size() - minLength);

        if (commonPrefixMap.find(prefix) != commonPrefixMap.end() &&
            commonSuffixMap.find(suffix) != commonSuffixMap.end()) {
            
            const std::vector<std::string>& prefixWords = commonPrefixMap[prefix];
            const std::vector<std::string>& suffixWords = commonSuffixMap[suffix];
            
            std::vector<int> countPrefix(prefixWords.size(), 3);
            std::vector<int> countSuffix(suffixWords.size(), 3);

            for (int i = 0; i < prefixWords.size(); ++i) {
                const std::string& prefixWord = prefixWords[i];

                for (int j = 3; j < prefixWord.size() && j < word.size(); ++j) {
                    if (prefixWord[j] == word[j]) {
                        countPrefix[i]++;
                    } else {
                        break;
                    }
                }
            }

            for (int i = 0; i < suffixWords.size(); ++i) {
                const std::string& suffixWord = suffixWords[i];

                for (int j = 3; j < suffixWord.size() && j < word.size(); ++j) {
                    if (suffixWord[suffixWord.size() - j - 1] == word[word.size() - j - 1]) {
                        countSuffix[i]++;
                    } else {
                        break;
                    }
                }
            }

            std::vector<std::pair<int, int>> indices;

            for (int i = 0; i < countPrefix.size(); i++) {
                for (int j = 0; j < countSuffix.size(); j++) {
                    if (countPrefix[i] + countSuffix[j] >= word.size()) {
                        indices.push_back({i, j});
                    }
                }
            }

            if (indices.empty()) {
                std::cout << "none" << std::endl;
            } else if (indices.size() > 1) {
                std::cout << "ambiguous" << std::endl;
            } else {
                std::cout << prefixWords[indices[0].first] << " " << suffixWords[indices[0].second] << std::endl;
            }
        } else {
            std::cout << "none" << std::endl;
        }
    }

    return 0;
}
