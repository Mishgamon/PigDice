//
// Created by Mishael Garrett on 10/6/26.
//
#include<iostream>
#include "Turn.h"
#include "PDGame.h"// 88888888

  Turn::Turn() {
      m_turnCount=0;
      m_scoreThisTurn=0;
      m_turnOver=false;
      m_choice=' ';
}
void Turn::setParentGame(PDGame* Papaoutai) {//Step 6 Eyes
     m_parentGame=Papaoutai;
  }

void Turn::roll() {
      m_myDie.roll();
      std::cout << "Die: " << m_myDie.getResult();
      if (m_myDie.getResult()==1) {
          m_choice='h';
          m_scoreThisTurn=0;
          m_turnOver=true;
          std::cout << "\nTurn over.  No score.";
      }else {
          m_scoreThisTurn+=m_myDie.getResult();
          std::cout<<" - Running score this turn: "<<m_scoreThisTurn;
      }
  }

void Turn::resetTurnOver() {
    m_turnOver=false;
      resetScoreThisTurn();
}

int Turn::getScoreThisTurn() {
    return m_scoreThisTurn;
}

int Turn::getTurnCount() {
    return m_turnCount;
}

void Turn::takeTurn() {
      m_turnCount++;
      std::cout << "\nTURN " << m_turnCount << " - Game Score: "<<m_parentGame->getGameScore();//9th Step. (The end)
      while (!m_turnOver) {
          std::cout << "\nroll or hold? (r/h): ";
          std::cin>>m_choice;
          if (m_choice == 'r') {
              roll();
          }else if (m_choice!='h'){
              std::cout << "\nInvalid Entry.  Please use 'r' for ''roll'' or 'h' for ''hold''.";

          }
          else {
              m_turnOver=true;
              std::cout<<"\nScore banked this turn: "<<m_scoreThisTurn;
          }
      }

}

void Turn::resetScoreThisTurn() {
m_scoreThisTurn=0;
}


