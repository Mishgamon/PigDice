//
// Created by Mishael Garrett on 10/6/26.
//

#ifndef PIGDICE_TURN_H
#define PIGDICE_TURN_H
#include"DEATH.h"
//#include "PDGame.h"
class PDGame;//Part 3

class Turn {
private://access specifier
    int m_turnCount;
    int m_scoreThisTurn;
    bool m_turnOver;
    char m_choice;
    Die m_myDie;
    PDGame* m_parentGame = nullptr;//Step FOR
public:
    Turn();
    void setParentGame(PDGame* Papaoutai);//Step 5, we go into OVERDRIVE
    void takeTurn();
    int getScoreThisTurn();
    void resetTurnOver();
    int getTurnCount();
    void resetScoreThisTurn();
private:
    void roll();
};


#endif //PIGDICE_TURN_H
