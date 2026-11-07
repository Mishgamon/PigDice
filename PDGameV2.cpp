//
// Created by Mishael Garrett on 11/5/26.
//

#include "PDGameV2.h"

std::string PDGameV2::getPlayerName() {
    return m_playerName;
}

PDGameV2::~PDGameV2() {

}

void PDGameV2::displayRules() {

}

void PDGameV2::playGame() {
    m_myTurn.resetTurnOver();
m_myTurn.takeTurn();
    m_gameScore+=m_myTurn.getScoreThisTurn();
}

int PDGameV2::getScore() {
    return m_gameScore;
}

