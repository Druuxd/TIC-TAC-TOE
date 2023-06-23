#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // initial values printed to the console

struct Player
{
    string name;
    char symbol;
    int score;
};

int score1 = 0;
int score2 = 0;

char turn;
Player player1;
Player player2;

// declaring the functions
bool gameOver();
void displayGame();
void playGame();
void playAgain(char x);
void players();

void players()
{

    cout << "Hello and Welcome! Please tell me your names" << endl;
    cout << "Player 1, what is your name?" << endl;
    cin >> player1.name;
    cout << "And what is your symbol?" << endl;
    cin >> player1.symbol;

    cout << "Player 2, what is your name?" << endl;
    cin >> player2.name;
    cout << "Since " << player1.name << " chose '" << player1.symbol << "', you have been attributed the symbol '";
    if (player1.symbol == 'X')
    {
        player2.symbol = 'O';
        turn = player1.symbol;
    }
    else
    {
        player2.symbol = 'X';
        turn = player2.symbol;
    }
    cout << player2.symbol << "'\n";

    system("pause");
}

// function to verify if the game has ended or if it needs to continue
bool gameOver()
{
    bool over = 0;

    // verify the diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        over = 1;
    }

    // verify rows and cols
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            over = 1;
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            over = 1;
        }
    }

    // if the game has ended, then:
    if (over == 1)
    {
        // At the end of the game, the turn changes for one last time, so we verify opposite values to find the winner.
        if (turn == player1.symbol) // if the turn has changed to X after the game ended, then the winner is O because player 2 was the one that made the last move.
        {
            cout << "Congrats " << player2.name << " you won!\n";
            cout << "Do you wish to play again? (y/n) \n";
            score2++;
            player2.score = score2;
            char x;
            cin >> x;
            playAgain(x); // replay the game
        }
        else if (turn == player2.symbol)
        {
            cout << "Congrats " << player1.name << " you won!\n";
            cout << "Do you wish to play again? (y/n) \n";
            score1++;
            player1.score = score1;
            char x;
            cin >> x;
            playAgain(x);
        }
    }

    // we assume the game is a draw.
    bool draw = 1;
    // we itterate through all positions on the board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // if we find a square that doesn't have the value of X or O, then the game is not a draw.
            if (board[i][j] != 'X' && board[i][j] != 'O')
                draw = 0;
        }
    }

    if (draw == 1)
    {
        cout << "The game ended in a draw!" << endl;
        cout << "Do you wish to play again? (y/n) \n";
        char x;
        cin >> x;
        playAgain(x);
    }

    return true; // the game is not a draw and the over value has not changed which means the game must continue.
}

void displayGame()
{

    // print a board to the console.
    system("cls");
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl
         << endl;
    cout << player1.name << "(" << player1.symbol << "): " << player1.score << endl;
    cout << player2.name << "(" << player2.symbol << "): " << player2.score << endl;
}

void playGame()
{

    int choice; // choose the square you want to occupy.

    while (gameOver()) // if the game hasn't ended keep playing
    {
        displayGame();

        cout << "Choose a square: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            if (board[0][0] != 'X' && board[0][0] != 'O') // verify if the square is not occupied
            {
                board[0][0] = turn; // the square take the value of the turn
                if (turn == player1.symbol)
                {
                    turn = player2.symbol; // change the turn value for the next player
                }
                else
                {
                    turn = player1.symbol; // change the turn value for the next player
                }
            }

            else
            {
                cout << "That square is already occupied, choose another one!" << endl;
                playGame(); // if the square is occupied then start again.
            }
            break;
        case 2:
            if (board[0][1] != 'X' && board[0][1] != 'O')
            {
                board[0][1] = turn;
                if (turn == player1.symbol)
                {
                    turn = player2.symbol; // change the turn value for the next player
                }
                else
                {
                    turn = player1.symbol; // change the turn value for the next player
                }
            }

            else
            {
                cout << "That square is already occupied, choose another one!" << endl;
                playGame();
            }
            break;
        case 3:
            if (board[0][2] != 'X' && board[0][2] != 'O')
            {
                board[0][2] = turn;
                if (turn == player1.symbol)
                {
                    turn = player2.symbol; // change the turn value for the next player
                }
                else
                {
                    turn = player1.symbol; // change the turn value for the next player
                }
            }

            else
            {
                cout << "That square is already occupied, choose another one!" << endl;
                playGame();
            }
            break;
        case 4:
            if (board[1][0] != 'X' && board[1][0] != 'O')
            {
                board[1][0] = turn;
                if (turn == player1.symbol)
                {
                    turn = player2.symbol; // change the turn value for the next player
                }
                else
                {
                    turn = player1.symbol; // change the turn value for the next player
                }
            }

            else
            {
                cout << "That square is already occupied, choose another one!" << endl;
                playGame();
            }
            break;
        case 5:
            if (board[1][1] != 'X' && board[1][1] != 'O')
            {
                board[1][1] = turn;
                if (turn == player1.symbol)
                {
                    turn = player2.symbol; // change the turn value for the next player
                }
                else
                {
                    turn = player1.symbol; // change the turn value for the next player
                }
            }

            else
            {
                cout << "That square is already occupied, choose another one!" << endl;
                playGame();
            }
            break;
        case 6:
            if (board[1][2] != 'X' && board[1][2] != 'O')
            {
                board[1][2] = turn;
                if (turn == player1.symbol)
                {
                    turn = player2.symbol; // change the turn value for the next player
                }
                else
                {
                    turn = player1.symbol; // change the turn value for the next player
                }
            }

            else
            {
                cout << "That square is already occupied, choose another one!" << endl;
                playGame();
            }
            break;
        case 7:
            if (board[2][0] != 'X' && board[2][0] != 'O')
            {
                board[2][0] = turn;
                if (turn == player1.symbol)
                {
                    turn = player2.symbol; // change the turn value for the next player
                }
                else
                {
                    turn = player1.symbol; // change the turn value for the next player
                }
            }

            else
            {
                cout << "That square is already occupied, choose another one!" << endl;
                playGame();
            }
            break;
        case 8:
            if (board[2][1] != 'X' && board[2][1] != 'O')
            {
                board[2][1] = turn;
                if (turn == player1.symbol)
                {
                    turn = player2.symbol; // change the turn value for the next player
                }
                else
                {
                    turn = player1.symbol; // change the turn value for the next player
                }
            }

            else
            {
                cout << "That square is already occupied, choose another one!" << endl;
                playGame();
            }
            break;
        case 9:
            if (board[2][2] != 'X' && board[2][2] != 'O')
            {
                board[2][2] = turn;
                if (turn == player1.symbol)
                {
                    turn = player2.symbol; // change the turn value for the next player
                }
                else
                {
                    turn = player1.symbol; // change the turn value for the next player
                }
            }

            else
            {
                cout << "That square is already occupied, choose another one!" << endl;
                playGame();
            }
            break;

        default:
            cout << "That square doesn't exist, try again!\n";
            playGame();
            break;
        }
    }
}

// funtion to restart the game
void playAgain(char x)
{
    if (x == 'y' || x == 'Y') // verify the choice of the player
    {
        board[0][0] = '1';
        board[0][1] = '2';
        board[0][2] = '3';
        board[1][0] = '4';
        board[1][1] = '5';
        board[1][2] = '6';
        board[2][0] = '7';
        board[2][1] = '8';
        board[2][2] = '9'; // reinitialize the values of the board

        char aux;
        aux = player2.symbol;
        player2.symbol = player1.symbol;
        player1.symbol = aux;

        if (player1.symbol == 'X')
        {
            turn = player1.symbol;
        }
        else
        {
            turn = player2.symbol;
        }

        playGame(); // restart game
    }
    else if (x == 'n' || x == 'N') // verify the choice of the player
    {
        system("cls");
        cout << "Okay then, have a nice day!\n";
        cout << "Final score is : \n"
             << player1.name << ": " << player1.score << "\n"
             << player2.name << ": " << player2.score << "\n";
        system("pause");
        exit(0); // exit the game
    }
    else
    {
        system("cls");
        cout << "Invalid choice, game will close now!";
        system("pause");
        exit(0);
    }
}

int main()
{

    cout << R"( _________  ___  ________               _________  ________  ________               _________  ________  _______      
|\___   ___\\  \|\   ____\             |\___   ___\\   __  \|\   ____\             |\___   ___\\   __  \|\  ___ \     
\|___ \  \_\ \  \ \  \___|  ___________\|___ \  \_\ \  \|\  \ \  \___|  ___________\|___ \  \_\ \  \|\  \ \   __/|    
     \ \  \ \ \  \ \  \    |\____________\  \ \  \ \ \   __  \ \  \    |\____________\  \ \  \ \ \  \\\  \ \  \_|/__  
      \ \  \ \ \  \ \  \___\|____________|   \ \  \ \ \  \ \  \ \  \___\|____________|   \ \  \ \ \  \\\  \ \  \_|\ \ 
       \ \__\ \ \__\ \_______\                \ \__\ \ \__\ \__\ \_______\                \ \__\ \ \_______\ \_______\
        \|__|  \|__|\|_______|                 \|__|  \|__|\|__|\|_______|                 \|__|  \|_______|\|_______|)"
         << "\n                                                                                                             -by Dru\n";
    system("pause");

    system("cls");

    players();

    playGame();

    return 0;
}