//
// Created by administrator on 9/24/26.
//

#ifndef PIGDICE_DIE_H //IF Not DEFined
#define PIGDICE_DIE_H
#include <random>


class Die {
private:
    int d_result;//dieValue
    int d_NumFaces=6;//numOfFaces
public:
    Die();
    Die(int numF);
    void rollDice();
    int getResult();
    void morph(int numF);
    int getNumF();
};

#endif //PIGDICE_DIE_H