#include <conio.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void concat(char* a, char* b) {
    int c = 0;
    for (int i = (int)strlen(a); i < strlen(a)+strlen(b); i++) {
        if (b[c] == '\0') {
            a[i] = '\0';
            break;
        }
        a[i] = b[c];
        c++;
    }
}

int main() {
    char a[10];
    char b[10];
    cout << "Enter first line:\n";
    cin >> a;
    cout << "Enter Second line:\n";
    cin >> b;

    concat(a, b);
    cout << "Result is : \n" << a;

    (void)_getch();
    return 0;
}