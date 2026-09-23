#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

// Build your solution starting from this code.

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};
class Die {
private:
    int d_result;
    int d_NumFaces=6;
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
        d_result = 0;
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

void add_score();
void display_rules();
void play_game(GameState &gs, Die &d);
void take_turn(GameState &g, Die &d);
int main() {
    Die Caroto;
    GameState my_game; // instantiate a GameState object
    display_rules(); // call the display_rules function
    play_game(my_game, Caroto); // call the play_game function and pass the GameState object
    return 0;
}

void add_score(GameState &gs) {
    gs.game_score += 10;
}

void display_rules() {
    std::cout << "Let's Play PIG Dice!\n * See how many turns it takes you to get to 20 points.\n * Turn ends when you hold or roll a 1.\n * If you roll a 1, you lose all points for the turn.\n * If you hold, you bank all points for the turn to the game score. \n";


}
void take_turn(GameState &game, Die &d) {
    std::cout << "\nroll or hold? (r/h): ";
    std::cin>>game.choice;
    if (game.choice == 'r') {

            d.rollDice();
            if (d.getResult()==1) {
                game.choice='h';
                game.score_this_turn=0;
                std::cout << "\nTurn over.  No score.";
            }else {
                game.score_this_turn+=d.getResult();
                std::cout<<" - Running score this turn: "<<game.score_this_turn;
            }
        }else if (game.choice!='h'){
            std::cout << "\nInvalid Entry.  Please use 'r' for ''roll'' or 'h' for ''hold''.";

        }
    if (game.choice != 'h') take_turn(game, d);

    }






void play_game(GameState &game, Die &d) {
    while (!game.game_over) {
    game.turn_count++;
    std::cout << "\nTURN " << game.turn_count << " - Game Score: " << game.game_score;
game.score_this_turn=0;
        take_turn(game, d);
        std::cout<<"\nScore banked this turn: "<<game.score_this_turn;
        game.game_score+=game.score_this_turn;
game.choice=' ';
        std::cout << "\n";
        if (game.game_score>=20)game.game_over=true;
}

std::cout << "\n\nYou finished with a final score of "<<game.game_score<<" in "<<game.turn_count<<" turn";
if (game.turn_count!=1)std::cout << "s";
    std::cout<<"!\nThanks for playing PIG dice!";

}



