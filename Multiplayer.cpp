//
// Created by Mishael Garrett on 11/5/26.
//

#include "Multiplayer.h"
#include <iostream>

void Multiplayer::startAllGames() {
    int playerz = 0;
    std::string name;
    std::cout<<"How many people are playing?  ";
    std::cin>>playerz;
    std::cin.ignore();
    int j = 1;
    for (int i = 0; i < playerz;i++) {

        std::cout<<"Enter player "<<(i+1)<<"'s name: ";
        std::cin>>name;
        if (name.empty()) {
            name = "Anonymous Player "+std::to_string(j);
            j++;
        }
        for (PDGameV2 k : m_players) {
            if (std::compareStr(name, k.getPlayerName())) {
                //fdjhkgfhsfe
            }
        }
        m_players.emplace_back(name);

    }
    std::cout <<
           "Let's Play PIG Dice!\n * See which player will reach 50 points in the fewest turns.\n * Turn ends when you hold or roll a 1.\n * If you roll a 1, you lose all points for the turn.\n * If you hold, you bank all points for the turn to the game score. \n";
    while (!m_allGameOver) {
        for (int i = 0; i < playerz; i++){
            std::cout<<m_players.at(i).getPlayerName();
            m_players.at(i).playGame();
            std::cout << "\n\n";
            targetScoreCheck(m_players.at(i).getScore());
            displayPoints(m_players);
            std::cout << "\n\n";
        }
    }
    declareWinner(m_players);
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

void Multiplayer::declareWinner(std::vector<PDGameV2> &players) {
    std::cout<<"Congratulations!  ";
    std::vector<PDGameV2> x;
    for (PDGameV2 i: m_players) {
        if (i.getScore()>=50)x.push_back(i);
    }
    std::string S = "Lord Chen";
    PDGameV2 winner(S);
    bool tie = false;
    for (PDGameV2 i:x) {
        if (i.getScore()>winner.getScore())winner=i;
        else if (i.getScore()==winner.getScore()) {
            bool greatest = true;
            for (PDGameV2 j:x) {
                if (j.getScore()>winner.getScore())greatest=false;
            }
            if (greatest) {
                tie=true;
                std::cout<<winner.getPlayerName()<<", ";
                winner = i;
            }
        }
    }
    if (!tie)std::cout<<winner.getPlayerName()<<" you win with a score of "<<winner.getScore();
    else std::cout<<winner.getPlayerName()<<" you tied with a score of "<<winner.getScore();
}

int Multiplayer::displayPoints(std::vector<PDGameV2> &players) {

    for (PDGameV2 i:m_players) {
        std::cout<<i.getPlayerName()<<" (Score: "<<i.getScore()<<") | ";
    }
}

Multiplayer::Multiplayer() {
    startAllGames();
}

Multiplayer::~Multiplayer() {

}
