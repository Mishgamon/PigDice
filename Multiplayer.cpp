//
// Created by Mishael Garrett on 11/5/26.
//

#include "Multiplayer.h"
#include <iostream>

void Multiplayer::startAllGames() {
    int playerz = 0;
    std::string name;
    std::cout<<"How many people are playing?";
    std::cin>>playerz;
    std::cin.ignore();
    for (int i = 0; i < playerz;i++) {
        std::cin>>name;
        m_players.emplace_back(name);
    }
    std::cout <<
           "Let's Play PIG Dice!\n * See which player will reach 50 points in the fewest turns.\n * Turn ends when you hold or roll a 1.\n * If you roll a 1, you lose all points for the turn.\n * If you hold, you bank all points for the turn to the game score. \n";
    while (!m_allGameOver) {
        for (int i = 0; i < playerz; i++){
            m_players.at(i).playGame();
            std::cout << "\n";
            Multiplayer::targetScoreCheck(m_players.at(i).getScore());
        }
    }
    declareWinner();
}

bool Multiplayer::targetScoreCheck(int score) {
    if (score>=50) {
        m_allGameOver=true;
        return true;
    }else if (m_allGameOver) {
        return true;
    }
    return false;
}

