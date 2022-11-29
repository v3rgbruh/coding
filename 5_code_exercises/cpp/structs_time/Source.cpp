#include <conio.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Time
{
    int Hour;
    int Minute;
};

Time sum(const Time a, const Time b){
    Time c;

    c.Minute = a.Minute + b.Minute;
    c.Hour = a.Hour + b.Hour;
    if (c.Minute > 59) {
        c.Hour++;
        c.Minute = c.Minute % 60;
    }
    c.Hour = c.Hour % 24;
    
    return c;
}

int main() {
    Time a;
    Time b;
    cout << "\t\tSumming two time variables\n";
    cout << "Enter first hour and minutes separated by space: ";
    cin >> a.Hour >> a.Minute;
    cout << "Enter second hour and minutes separated by space: ";
    cin >> b.Hour >> b.Minute;

    Time c = sum(a, b);
    cout << "\nSum of " << a.Hour << ":" << a.Minute << " and "
         << b.Hour << ":" << b.Minute << " is: " \
         << c.Hour << ":" << c.Minute;

    (void)_getch();
    return 0;
}