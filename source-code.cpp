#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// Global-Variables
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char current_marker;
int current_player;

// Board
void drawboard(){
    for(int i = 0 ; i<3 ; i++){
        for(int j = 0 ; j < 1 ; j++){
            cout<<"   "<<board[i][j]<<"   |   "<<board[i][j+1]<<"   |   "<<board[i][j+2]<<" "<<endl;
            cout<<"----------------------"<<endl;
        }
    }
}
// Marker after every iteration by the user
bool placemarker(int slot){
    int row = slot/3,col;
    if(slot % 3 == 0){
        row = row -1;
        col = 2;
    }
    else{
        col = (slot % 3) - 1;
    }
    if(board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = current_marker;
        return true;
    }
    else{
        return false;
    }
}

// Function that swaps pair and marker

void swap_player_and_marker(){
    if(current_marker == 'X'){
        current_marker = 'O';
    }
    else{
        current_marker = 'X';
    }
    if(current_player == 1){
        current_player = 2;
    }
    else{
        current_player = 1;
    }
}

// Winner-Function
int winner(){
    for(int i = 0 ; i<3 ; i++){
        //Rows
        if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])){
            return current_player;
        }
        //Columms
        if((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])){
            return current_player;
        }
    }
    if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])){
        return current_player;
    }
    if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])){
        return current_player;
    }
    return 0;
}

// Game-Interface
void game(){
    char marker_p1,marker_p2;
    cout<<"Choose X or O as input for your marker "<<endl;
    cout<<"Marker for player 1 : ";
    cin>>marker_p1;

    current_player = 1;
    current_marker = marker_p1;
    int player_won;
    for(int i = 0 ; i<9 ; i++){
        cout<<"It's player "<<current_player<<" turn. Enter your slot: ";
        int slot;
        cin>>slot;
        if(slot < 1 && slot > 9){
            cout<<"That slot is invalid! Try another slot!"<<endl;
            i--;
            continue;
        }
        if(!placemarker(slot)){
            cout<<"That slot is occupied! Try another slot!"<<endl;
            i--;
            continue;
        }
        drawboard();
        player_won = winner();
        if(player_won == 1){
            cout<<"Player 1 has Won!!"<<endl;
            break;
        }
        if(player_won == 2){
            cout<<"Player 2 has Won!!"<<endl;
            break;
        }
        swap_player_and_marker();
    }
    if(player_won == 0){
        cout<<"It's a Tie!!"<<endl;
    }
}

// Main-Driver Code
int main(){
    cout<<"                                                         Tic-Tac-Toe"<<endl;
    drawboard();
    cout<<endl;
    game();
    system("pause");
    return 0;
}