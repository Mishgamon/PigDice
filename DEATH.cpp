//
// Created by administrator on 9/29/26.
//


#include <iostream>
#include <random>
#include "DEATH.h"
Die::Die() {
    d_NumFaces=6;
    rollDice();
}
Die::Die(int numF) {
    if (numF%2==0&&numF<10&&numF>0)d_NumFaces=numF;
    else d_NumFaces=6;
}
void Die::rollDice() {
    std::random_device srand;
    std::mt19937 gen(srand());
    std::uniform_int_distribution<> dist(1, 6);
    d_result = dist(gen);


}
int Die::getResult() {//get_dieValue
    return d_result;
}

void Die::morph(int numF) {//set_numOfFaces
    switch (numF) {
        case 2:d_NumFaces=2; break;
        case 4:d_NumFaces=4; break;
        case 6:d_NumFaces=6; break;
        case 8:d_NumFaces=8; break;
    }
}
int Die::getNumF() {//get_numOfFaces
    return d_NumFaces;
}