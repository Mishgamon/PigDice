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
    bool m_allGameOver=0;
public:
    Multiplayer();
    ~Multiplayer();
    void startAllGames();
private:
    int displayPoints(std::vector<PDGameV2> &players);
    bool targetScoreCheck(int score);
    void declareWinner(std::vector<PDGameV2> &players);


};


#endif //PIGDICE_MULTIPLAYER_H
