#include <iostream>
#include <conio.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

const int MAX = 5;

struct Cars
{
    char* Brand;
    char* Mark;
    int Year;
    double LiterCapacity;
};

void fillCarInfo(Cars* arr) {
    srand(rand());
    char Brands[MAX][20] = {"Mazda", "BMW", "Honda", "Hyundai", "Mercedes"};
    char* brand = Brands[rand() % MAX];
    brand[strlen(brand)] = '\0';
    arr->Brand = new char[20];
    memcpy(arr->Brand, brand, strlen(brand)+1);
    arr->Mark = new char[20] {"Thing"};
    arr->LiterCapacity = 2.2;
    arr->Year = 1970 + rand() % 50;
}

void PrintCars(Cars* arr) {
    cout << "We have " << MAX << " cars:\n";
    for (int i = 0; i < MAX; i++) {
        cout << "\t" << i+1 << ". " << arr[i].Brand << " " \
             << arr[i].Mark << " " \
             << arr[i].Year << " year with a " \
             << arr[i].LiterCapacity << " liter cap\n";
    }
}

int main() {
    Cars arr[MAX];

    for (int i = 0; i < MAX; i++) {
        fillCarInfo(&arr[i]);
    }
    PrintCars(arr);


    (void)_getch();
    return 0;
}