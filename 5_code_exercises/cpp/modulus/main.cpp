#include <conio.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

long double modulus(long double a) { return abs(a); }

int main() {
    long double a;
    cout << "\t\tFinding modulus\n";
    cout << "Enter number: ";
    cin >> a;

    cout << endl << endl << modulus(a);

    _getch();
    return 0;
}