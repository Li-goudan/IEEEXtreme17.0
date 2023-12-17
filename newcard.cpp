#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <ctime>

int determineWinner(std::vector<std::queue<char>>& playerCards) {
    int i = 0;

    while (!playerCards[0].empty() && !playerCards[1].empty()) {
        char card1, card2;
        if (i++ > 10000) break;

        card1 = playerCards[0].front();
        card2 = playerCards[1].front();
        playerCards[0].pop();
        playerCards[1].pop();

        std::map<char, int> cardValue = {{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
                                        {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};

        if (cardValue[card1] == cardValue[card2]) {
            playerCards[0].push(card1);
            playerCards[1].push(card2);
        } else {
            if (cardValue[card1] > cardValue[card2]){
                playerCards[0].push(card2);
            }
            else{
                playerCards[1].push(card1);
            }
        }
    }

    if (playerCards[0].empty()) return 2;
    if (playerCards[1].empty()) return 1;
    else return 0;

    return -1;
}

int main() {
    int numGames;
    std::cin >> numGames;
    int winner[numGames];

    for (int game = 0; game < numGames; ++game) {
        std::vector<std::queue<char>> playerCards(2);

        for (int player = 0; player < 2; ++player) {
            char card;

            while (std::cin >> card){
                playerCards[player].push(card);
                if (std::cin.get() == '\n'){
                    break;
                }
            }
        }
        winner[game] = determineWinner(playerCards);

    }

    for (const auto &w : winner) {
        if (w == 1) {
            std::cout << "player 1" << std::endl;
        } else if (w == 2) {
            std::cout << "player 2" << std::endl;
        } else {
            std::cout << "draw" << std::endl;
        }
    }

    return 0;
}
