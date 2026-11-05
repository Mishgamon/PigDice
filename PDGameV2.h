//
// Created by Mishael Garrett on 11/5/26.
//

#ifndef PIGDICE_PIGDICEV2_H
#define PIGDICE_PIGDICEV2_H
#include<iostream>
#include "PDGame.h"


class PDGameV2: public PDGame {
    std::string m_playerName;
public:
    PDGameV2(std::string &name) {
        m_playerName=name;
    }
    ~PDGameV2();
    std::string getPlayerName();
    void playGame();
private:
    void displayRules();


};


#endif //PIGDICE_PIGDICEV2_H
