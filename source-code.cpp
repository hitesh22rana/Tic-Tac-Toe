#include <bits/stdc++.h>
using namespace std;

// Global-Variables

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

string Toss, player_1, player_2;

char current_marker;
string current_player;

// Board

void drawboard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cout << "   " << board[i][j] << "   |   " << board[i][j + 1] << "   |   " << board[i][j + 2] << " " << endl;
            cout << "----------------------" << endl;
        }
    }
}

// Toss to select player 1 & player 2

string toss ()
{
    string Name1, Name2;
    Name1 = Name2 = "";
    cout<<"Enter name of player 1: ";
    fflush(stdin);
    getline(cin, Name1);

    cout<<"Enter name of player 2: ";
    fflush(stdin);
    getline(cin, Name2);

    cout<<"\nToss is in progress... ";
    system("pause");

    srand(time(0));

    if((rand() % 5))
    {
        Toss = Name1;
        player_1 = Name1;
        player_2 = Name2;
    }
    else
    {
        Toss = Name2;
        player_1 = Name2;
        player_2 = Name1;
    }

    cout<<"\nToss won by "<<Toss<<endl;
    cout<<"\nPLAYER 1: "<<player_1<<endl;
    cout<<"PLAYER 2: "<<player_2<<endl;

    cout<<endl;
    system("pause");

    return Toss;
}

// Marker after every iteration by the user
bool placemarker(int slot)
{
    int row = slot / 3, col;
    if (slot % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }
    else
    {
        col = (slot % 3) - 1;
    }
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = current_marker;
        return true;
    }
    else
    {
        return false;
    }
}

// Function that swaps pair and marker

void swap_player_and_marker()
{
    if (current_marker == 'X')
    {
        current_marker = 'O';
    }
    else
    {
        current_marker = 'X';
    }

    if (current_player == player_1)
    {
        current_player = player_2;
    }
    else
    {
        current_player = player_1;
    }
}

// Winner-Function
int winner()
{
    for (int i = 0; i < 3; i++)
    {
        //Rows
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
        {
            return 1;
        }
        //Columms
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
        {
            return 1;
        }
    }
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
    {
        return 1;
    }
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
    {
        return 1;
    }
    return 0;
}

// Game-Interface
void game()
{
    current_player = toss();
    cout << endl << endl;

    drawboard();
    cout << endl << endl;
    
    char marker_p1, marker_p2;
    cout << "Choose X or O as input for your marker " << endl;
    cout << endl;

    cout << "Marker for " << player_1 << " : ";
    cin >> marker_p1;

    current_marker = marker_p1;
    cout << endl;

    for (int i = 0; i < 9; i++)
    {
        cout << "It's " << current_player << " 's turn!" << endl;
        cout << "Enter your slot: ";
        int slot;
        cin >> slot;
        if (slot < 1 && slot > 9)
        {
            cout << "That slot is invalid! Try another slot!" << endl;
            i--;
            continue;
        }
        if (!placemarker(slot))
        {
            cout << "That slot is occupied! Try another slot!" << endl;
            i--;
            continue;
        }

        cout << endl;
        drawboard();
        if (winner())
        {
            cout << current_player << " has Won!!" << endl;
            break;
        }
        swap_player_and_marker();
        cout << endl << endl;
    }
    if (!winner())
    {
        cout << "It's a Tie!!" << endl;
    }
}

// Main-Driver Code
int main()
{
    system("cls");
    
    cout << "                                                         Tic-Tac-Toe" << endl;
    cout << endl;
    game();
    system("pause");
    return 0;
}