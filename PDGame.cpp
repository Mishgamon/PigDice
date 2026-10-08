//
// Created by Mishael Garrett on 10/6/26.
//
#include <iostream>
#include "PDGame.h"
#include "Turn.h"
PDGame::PDGame() {
    m_myTurn;
    m_gameOver=false;
    m_gameScore=0;
    displayRules();
    playGame();
}

void PDGame::displayRules() {
    std::cout <<
            "Let's Play PIG Dice!\n * See how many turns it takes you to get to 20 points.\n * Turn ends when you hold or roll a 1.\n * If you roll a 1, you lose all points for the turn.\n * If you hold, you bank all points for the turn to the game score. \n";
}

void PDGame::playGame() {
    while (!m_gameOver) {
        m_myTurn.takeTurn();
        m_gameScore+=m_myTurn.getScoreThisTurn();
        std::cout << "\n";
        if (m_gameScore>=20)m_gameOver=true;
        else m_myTurn.resetTurnOver();
    }
    std::cout << "\n\nYou finished with a final score of "<<m_gameScore<<" in "<<m_myTurn.getTurnCount()<<" turn";
    if (m_myTurn.getTurnCount()!=1)std::cout << "s";
    std::cout<<"!\nThanks for playing PIG dice!";
}
