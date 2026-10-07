//
// Created by Mishael Garrett on 10/6/26.
//

#ifndef PIGDICE_TURN_H
#define PIGDICE_TURN_H
#include"DEATH.h"

class Turn {
private://access specifier
    static int m_turnCount;
    int m_scoreThisTurn;
    bool m_turnOver;
    char m_choice;
    Die m_myDie;
public:
    Turn();
    Turn(int &gameScore);
    void takeTurn();
    int getScoreThisTurn();
    void resetTurnOver();
    int getTurnCount();
    void resetGameOver();
private:
    void roll();
};


#endif //PIGDICE_TURN_H
