#include <iostream>
#include <ostream>
#include <fstream>
#include <conio.h>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::fopen;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::string;

void out(ostream &out) { out << "Hello"; }

int main() {
    //ofstream fout("test.txt");
    //out(cout);
    //out(fout);

    ifstream fin;
    fin.open("test.txt");

    if (!fin.is_open())
    {
        cout << "no file exists";
        return -1;
    }

    int n = 0;
    string temp;
    while (!fin.eof()) {
        fin >> temp;
        cout << temp;
        n++;
    }


    (void)_getch();
    return 0;
}