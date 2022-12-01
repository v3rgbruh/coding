#include <conio.h>
#include <iostream>
#include <type_traits>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template<typename T>
void sort(T &a) {
    for (int i = 1; i < sizeof(a) / sizeof(*a); i++)
        for (int j = 0; j < (sizeof(a) / sizeof(*a)) - 1; j++) {
            if (a[i] < a[j]) {
                auto temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
}

template<typename T, typename B>
auto find(B b, T &a) -> decltype(b) {
    for (int i = 1; i < sizeof(a) / sizeof(*a); i++)
        if (a[i] == b)
            return i;
    return 0;
}

template<typename T>
double mean(T &a) {
    double tmp = 0;
    int arrsize = sizeof(a) / sizeof(*a);
    for (int i = 0; i < arrsize; i++)
        tmp += a[i];
    return double(tmp / arrsize);
}

int main() {
    int a[] = { 6,4,1,7,5 };
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;

    int input = NULL;
    cout << "Enter array command: \n";
    cout << "\t1. sort\n";
    cout << "\t2. mean number\n";
    cout << "\t3. find element\n";
    while (!input || !(input > 0 && input < 4) ) {
        cin >> input;
    }
    switch (input) {
        case 1:
        {
            sort(a);
            for (int i = 0; i < 5; i++)
                cout << a[i] << " ";
            cout << endl;
            break;
        }
        case 2:
            cout << mean(a);
            break;
        case 3:
        {
            cin >> input;
            cout << "index of " << input << " is : " << find(input, a);
        }
    }

    (void)_getch();
    return 0;
}