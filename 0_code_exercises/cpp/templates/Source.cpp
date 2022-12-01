#include <conio.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

template<typename T>
void swap(T& a, T& b) {
    T temp = b;
    b = a;
    a = temp;
}


int main() {
    int a = 1, b = 2;
    string astr = "a", bstr = "b";
    cout << "a: " << a << ", b:" << b << endl << "astr: " << astr << ", bstr:" << bstr << endl;
    cout << "_______________" << endl;
    swap(a, b);
    swap(astr, bstr);
    cout << "a: " << a << ", b:" << b << endl << "astr: " << astr << ", bstr:" << bstr << endl;


    (void)_getch();
    return 0;
}