#include <iostream>
#include <conio.h>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int SIZE = 3;

bool checkInput(int* a) {
    if (!(cin >> *a) || (*a < 1 || *a > 9)) {
        *a = 0;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void printTable(int(*t)[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            string field = "  |";
            switch ((*t)[i][j]) {
                case 1: field = "O |"; break;
                case 2: field = "X |"; break;
                default: break;
            }
            cout << field;
        }
        cout << endl;
    }
}

bool markField(int(*t)[SIZE][SIZE], bool* isFirstPlayer, int input) {
    if (input == 0) return false;

    int row = int((input -1) / SIZE);
    int col = int((input -1) % SIZE);
    
    if ((*t)[row][col] != 1 && (*t)[row][col] != 2) {
        *isFirstPlayer = !(*isFirstPlayer);
        (*t)[row][col] = *isFirstPlayer ? 1 : 2;
        return true;
    }
    return false;
}

bool checkWin(int (*t)[SIZE][SIZE], bool* isFirstPlayer) {
    // check \ diagonal
    int count = 0;
    for (int i = 0; i < SIZE; i++)
        if ((*t)[i][i] == (*isFirstPlayer ? 1 : 2)) count++;
    if (count > 2)
        return true;

    // check / diagonal
    count = 0;
    for (int i = SIZE-1; i >= 0; i--)
        if ((*t)[i][SIZE-1 - i] == (*isFirstPlayer ? 1 : 2)) count++;
    if (count > 2)
        return true;

    // check rows
    for (int i = 0; i < SIZE; i++){
        count = 0;
        for (int j = 0; j < SIZE; j++)
            if ((*t)[i][j] == (*isFirstPlayer ? 1 : 2)) count++;
        if (count > 2)
            return true;
    }

    // check cols
    for (int i = 0; i < SIZE; i++){
        count = 0;
        for (int j = 0; j < SIZE; j++)
            if ((*t)[j][i] == (*isFirstPlayer ? 1 : 2)) count++;
        if (count > 2)
            return true;
    }

    return false;
}

int main() {
    int table[SIZE][SIZE] = {0};
    int leftTurns = SIZE * SIZE;

    int input = 0;
    bool firstPlayer = false;
    bool gameOver = false;

    while (!gameOver) {
        do {
            system("cls");
            if (markField(&table, &firstPlayer, input))
                leftTurns--;

            printTable(&table);
            if (input != 0 && checkWin(&table, &firstPlayer)){
                gameOver = true;
                break;
            }
            if (leftTurns <= 0) {
                cout << "\n\t\tDraw!";
                (void)_getch();
                return 0;
            }

            cout << "Enter field: ";
        } while (!checkInput(&input));
    }
    cout << "\n\t\tPlayer " << (int)!firstPlayer + 1 << " wins!";

    (void)_getch();
    return 0;
}