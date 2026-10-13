//
// Created by Mishael Garrett on 10/6/26.
//

#ifndef PIGDICE_PDGAME_H
#define PIGDICE_PDGAME_H
#include "Turn.h"

class PDGame {
private:
    Turn m_myTurn;
    bool m_gameOver;
    int m_gameScore;
public:
    PDGame();
    int getGameScore();  //Step 1 of Workaround for whole-to-part info transfer
private:
    void displayRules();
    void playGame();
};


#endif //PIGDICE_PDGAME_H
