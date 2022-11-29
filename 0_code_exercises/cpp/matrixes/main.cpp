#include <iostream>
#include <cstdio>
#include <conio.h>

using std::cin;
using std::cout;
using std::endl;

int** setupMatrix(short siz) {
    int** p = new int* [siz];
    for (int i(0); i < siz; i++)
        p[i] = new int[siz];
    cout << endl;
    for (int i(0); i < siz; i++) {
        cout << "Enter three numbers separated by space: ";
        for (int j(0); j < siz; j++) {
            cin >> p[i][j];
        }
    }
    return p;
}

void resultMatrixes(short siz, int** p1, int** p2, int** p3) {
    for (int i(0); i < siz; i++) {
        for (int j(0); j < siz; j++) {
            cout << p1[i][j] << " ";
        }
        cout << "\t\tX\t";
        for (int j(0); j < siz; j++) {
            cout << p2[i][j] << " ";
        }
        cout << "\t\t=\t";
        for (int j(0); j < siz; j++) {
            for (int m(0); m < siz; m++) {
                p3[i][j] += p1[i][m] * p2[m][j];
            }
            cout << p3[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteMatrix(short siz, int** p) {
    for (int i(0); i < siz; i++)
        delete[] p[i];
    delete[] p;
}

int main() {
    const int siz = 3;

    cout << "First matrix setting:\n";
    int** p1 = setupMatrix(siz);
    cout << "\nSecond matrix setting:\n";
    int** p2 = setupMatrix(siz);

    int** p3 = new int* [siz];
    for (int i(0); i < siz; i++) {
        p3[i] = new int[siz];
    }
    for (int i(0); i < siz; i++) {
        for (int j(0); j < siz; j++) {
            p3[i][j] = 0;
        }
    }

    system("cls");
    resultMatrixes(siz, p1, p2, p3);

    deleteMatrix(siz, p1);
    deleteMatrix(siz, p2);
    _getch();
    return 0;
}