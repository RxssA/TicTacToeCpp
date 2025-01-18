#include<iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char playerMarker);
void computerMove(char *spaces, char computerMarker);
bool checkWinner(char *spaces, char playerMarker);
bool checkTie(char *spaces);

int main()
{
    srand(time(0));
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char playerMarker = 'X';
    char computerMarker = 'O';
    bool running = true;

    drawBoard(spaces);

    while(running){
        playerMove(spaces, playerMarker);
        drawBoard(spaces);
        if(checkWinner(spaces, playerMarker)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }

        computerMove(spaces, computerMarker);
        drawBoard(spaces);
        if(checkWinner(spaces, computerMarker)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
    }
    std::cout << "Thanks for playing!\n";

    return 0;
}
void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}
void playerMove(char *spaces, char player){
    int number;
    do{
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' '){
           spaces[number] = player;
           break; 
        }
    }while(!number > 0 || !number < 8);
}
void computerMove(char *spaces, char computerMarker){
    int number;
    

    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computerMarker;
            break;
        }
    }
}
bool checkWinner(char *spaces, char playerMarker) {
    int winningCombinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Columns
        {0, 4, 8}, {2, 4, 6}              // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (spaces[winningCombinations[i][0]] == playerMarker &&
            spaces[winningCombinations[i][1]] == playerMarker &&
            spaces[winningCombinations[i][2]] == playerMarker) {
            std::cout << (playerMarker == 'X' ? "YOU WIN!\n" : "YOU LOSE!\n");
            return true;
        }
    }
    return false;
}

bool checkTie(char *spaces){

    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout << "IT'S A TIE!\n";
    return true;
}