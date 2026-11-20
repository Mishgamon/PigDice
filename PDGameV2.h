//
// Created by Mishael Garrett on 11/5/26.
//

#ifndef PIGDICE_PIGDICEV2_H
#define PIGDICE_PIGDICEV2_H
#include<iostream>
#include "PDGame.h"


class PDGameV2: public PDGame {
    std::string m_playerName;
    int m_gameScore=0;
public:
    PDGameV2(std::string &name) {
        m_playerName=name;
    }
    ~PDGameV2();
    std::string getPlayerName();
    void playGame();
    int getScore();
    bool operator>(PDGameV2 righto) {
        if (this->getScore()>=righto.getScore()) {
            return true;
        }else return false;
    }

private:
    void displayRules();


};


#endif //PIGDICE_PIGDICEV2_H
