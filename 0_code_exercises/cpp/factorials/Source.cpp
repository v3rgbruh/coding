#include <iostream>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;
typedef double big;

bool checkInput(big* a,big* b) {
    if (!(cin >> *a >> *b) || *a < 0 || *b < 0 || *a < *b)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}
big fac(big a) { return a == 1 ? 1 : a * fac(a - 1); }
big variations(big* a, big* b) { return fac(*a) / big(fac(*a - *b) * fac(*b)); }
int main() {
    big a, b;
    do {
        system("cls");
        cout << "Enter two numbers for variations from a by b: ";
    } while (!checkInput(&a, &b));
    cout << "Factorial of " << a << " is " << fac(a) << endl;
    cout << "Variations from " << a << " by " << b << " is: " << variations(&a, &b);

    _getch();
    return 0;
}