#include <iostream>

// Build your solution starting from this code.

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};
int roll_dice();
void add_score();
void display_rules();
void play_game(GameState &gs);
void take_turn(GameState &g);
int main() {
    GameState my_game; // instantiate a GameState object
    display_rules(); // call the display_rules function
    play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}

void add_score(GameState &gs) {
    gs.game_score += 10;
}

void display_rules() {
    std::cout << "Let's Play PIG Dice!\n * See how many turns it takes you to get to 20 points.\n * Turn ends when you hold or roll a 1.\n * If you roll a 1, you lose all points for the turn.\n * If you hold, you bank all points for the turn to the game score. \n";


}
void take_turn(GameState &game) {
    std::cout << "\nroll or hold? (r/h): ";
    std::cin>>game.choice;
    if (game.choice == 'r') {

            int x = roll_dice();
            if (x==1) {
                game.choice='h';
                game.score_this_turn=0;
                std::cout << "\nTurn over.  No score.";
            }else {
                game.score_this_turn+=x;
                std::cout<<" - Running score this turn: "<<game.score_this_turn;
            }
        }else if (game.choice!='h'){
            std::cout << "\nInvalid Entry.  Please use 'r' for ''roll'' or 'h' for ''hold''.";

        }
    if (game.choice != 'h') take_turn(game);

    }





int roll_dice() {
    int x = (rand() % 6)+1;
    std::cout << "Die: " << x;
    return x;
}

void play_game(GameState &game) {
    while (!game.game_over) {
    game.turn_count++;
    std::cout << "\nTURN " << game.turn_count << " - Game Score: " << game.game_score;
game.score_this_turn=0;
        take_turn(game);
        std::cout<<"\nScore banked this turn: "<<game.score_this_turn;
        game.game_score+=game.score_this_turn;
game.choice=' ';
        std::cout << "\n";
        if (game.game_score>=20)game.game_over=true;
}

std::cout << "\nYou finished with a final score of "<<game.game_score<<" in "<<game.turn_count<<" turn";
if (game.turn_count!=1)std::cout << "s";
    std::cout<<"!\nThanks for playing PIG dice!";

}



