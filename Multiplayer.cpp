//
// Created by Mishael Garrett on 11/5/26.
//

#include "Multiplayer.h"
#include <iostream>
#include <vector>

void Multiplayer::startAllGames() {
    int playerz = 0;
    bool repeat = true;
    std::string name;
    while (1==1) {
        try {
            std::cout<<"How many people are playing?  ";
            std::cin>>playerz;
            if (std::cin.fail()){throw 256;}
            if (playerz>5||playerz<1){throw 21;}
            std::cin.ignore();
            break;
        }catch (int e) {

            std::cin.clear();
            std::cin.ignore(100,'\n');
            std::cerr<<"\nEnter an integer from 1-5."<<std::endl;


        }
    }
    int j = 1;
    for (int i = 0; i < playerz;i++) {

        while (repeat) {
            repeat=false;

            std::cout<<"Enter player "<<(i+1)<<"'s name: ";
            std::getline(std::cin,name);
            if (name.empty()) {
                name = "Anonymous Player "+std::to_string(j);
                j++;
            }
            for (PDGameV2 k : m_players) {
                if (name==k.getPlayerName()) {
                    repeat=true;
                    std::cout<<"That name is already taken.  Please enter a unique name.\n";
                }
            }
        }
        m_players.emplace_back(name);
        repeat=true;
    }
    std::cout <<
           "Let's Play PIG Dice!\n * See which player will reach 50 points in the fewest turns.\n * Turn ends when you hold or roll a 1.\n * If you roll a 1, you lose all points for the turn.\n * If you hold, you bank all points for the turn to the game score. \n";
    while (!m_allGameOver) {
        for (int i = 0; i < playerz; i++){
            std::cout<<m_players.at(i).getPlayerName();
            m_players.at(i).playGame();
            std::cout << "\n\n";
            targetScoreCheck(m_players.at(i).getGameScore());
            displayPoints();
            std::cout << "\n\n";
        }
    }
    std::cout<<"Congratulations!  ";
    declareWinner(0,1);
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

void Multiplayer::declareWinner(int index, int next) {

/*    std::vector<PDGameV2> over50;
    for (PDGameV2 i: m_players) {
        if (i.getScore()>=50)over50.push_back(i);
    }
    std::string S = "Lord Chen";
    PDGameV2 winner(S);
    bool tie = false;
    for (PDGameV2 i:over50) {
        if (i.getScore()>winner.getScore())winner=i;
        else if (i.getScore()==winner.getScore()) {
            bool greatest = true;
            for (PDGameV2 j:over50) {
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
    */
    if (m_players.size()<=next) {
        std::cout<<m_players.at(index).getPlayerName()<<" you win with a score of "<<m_players.at(index).getGameScore();

    }
    else if (m_players.at(index)>m_players.at(next)) {
    declareWinner(index,next+1);
}else declareWinner(next,next+1);
}

int Multiplayer::displayPoints() {

    for (PDGameV2 i:m_players) {
        std::cout<<i.getPlayerName()<<" (Score: "<<i.getGameScore()<<") | ";
    }
}

Multiplayer::Multiplayer() {
    startAllGames();
}

Multiplayer::~Multiplayer() {

}
