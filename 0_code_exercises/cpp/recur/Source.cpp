#include <iostream>
#include <conio.h>
#include <time.h>
#include <random>

using std::cout;
using std::cin;
using std::endl;

int fac(int a) { return a == 0 ? 1 : a * fac(a - 1); }

template <typename T>
void quicksort(T arr, int l, int r) {
    int i = l, j = r;
    int mid = arr[(i + j) / 2];

    do {
        while (mid > arr[i]) i++;
        while (mid < arr[j]) j--;

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }

    } while (i < j);

    if (i < r) quicksort(arr, i, r);
    if (j > l) quicksort(arr, l, j);
}

template <typename T1, typename T2>
int find(T1 &arr, T2 number, int l, int r) {
    int mid = (l + r) / 2;
    if (arr[mid] == number)
        return mid;

    if (arr[mid] > number) return find(arr, number, l, mid);
    if (arr[mid] < number) return find(arr, number, mid, r);
    return NULL;
}

int main() {
    int a = 11;
    cout << "Factorial of " << a << " is : " << fac(a) << endl;

    const int MAX = 5000000;
    int* arr = new int[MAX];
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand();
    }

    cout << "Sorting array of " << MAX << " random elements...\n";
    double t1 = clock();
    quicksort(arr, 0, MAX - 1);
    double t2 = clock() - t1;

    //for (int i = 0; i < MAX; i++) {
    //    cout << arr[i] << " ";
    //}
    //cout << endl;
    //double t3 = clock() - t2;
    cout << "Sorting takes " << t2 / CLOCKS_PER_SEC << "s time to complete" << endl;
    //cout << "Printing results takes " << t3 / CLOCKS_PER_SEC << "s time to complete" << endl;

    int number = 1025;
    if (auto idx = find(arr, number, 0, MAX - 1))
        cout << "Finded '" << number << "' number in array (" << arr[idx] << "), it has position of " << idx << endl;
    else
        cout << "Didn't find '" << number << "' number in array" << endl;
    cout << "Finding element takes " << (clock() - t2) / CLOCKS_PER_SEC << "s time to complete" << endl;

    delete[] arr;
    (void)_getch();
    return 0;
}