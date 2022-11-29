#include <iostream>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;
typedef unsigned long long big;

big fac(big n) { return 1 == n ? 1 : n * fac(n - 1); }
double series(big* a) {

    return *a;
}
bool checkInput(big* n) {
    if (!(cin >> *n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}
int main() {
    big n;
    do {
        system("cls");
        cout << "Input number: ";
    } while (!checkInput(&n));

    cout << "\nApprox number of taylor series via 20 repetitions is: " << series(&n);

    _getch();
    return 0;
}