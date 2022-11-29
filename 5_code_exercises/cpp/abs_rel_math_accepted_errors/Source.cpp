#include <conio.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

long double absolute_error(long double, long double);
long double relative_error(long double, long double);

int main() {
    long double a;
    long double b;
    cout << "Enter needed number: ";
    cin >> a;
    cout << "Enter real number: ";
    cin >> b;

    cout << endl << "Absolute error of " << a << " is: " << absolute_error(a, b);
    cout << endl << "Relative error of " << a << " is: " << relative_error(a, b);

    _getch();
    return 0;
}

long double absolute_error(long double a, long double b) {
    return abs(a - b);
}

long double relative_error(long double a, long double b) {
    return absolute_error(a, b) / b;
}