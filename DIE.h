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
    void rollDice() {
        std::random_device srand;
        std::mt19937 gen(srand());
        std::uniform_int_distribution<> dist(1, 6);
        d_result = dist(gen);
        std::cout << "Die: " << d_result;

    }
    int getResult() {//get_dieValue
        return d_result;
    }
    Die() {
        d_NumFaces=6;
        rollDice();
    }
    Die(int numF) {
        if (numF%2==0&&numF<10&&numF>0)d_NumFaces=numF;
        else d_NumFaces=6;
    }
    void morph(int numF) {//set_numOfFaces
        switch (numF) {
            case 2:d_NumFaces=2; break;
            case 4:d_NumFaces=4; break;
            case 6:d_NumFaces=6; break;
            case 8:d_NumFaces=8; break;
        }
    }
    int getNumF() {//get_numOfFaces
        return d_NumFaces;
    }
};

#endif //PIGDICE_DIE_H