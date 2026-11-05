//
// Created by Mishael Garrett on 11/5/26.
//

#ifndef PIGDICE_MULTIPLAYER_H
#define PIGDICE_MULTIPLAYER_H
#include <vector>
#include "PDGameV2.h"

class Multiplayer {
    std::vector<PDGameV2> m_players;
    bool m_playerReachedTargetScore;
    bool m_allGameOver;
public:
    Multiplayer();
    ~Multiplayer();
    void startAllGames();
private:
    int displayPoints();
    bool targetScoreCheck(int score);
    void declareWinner();


};


#endif //PIGDICE_MULTIPLAYER_H
