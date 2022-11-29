#include <conio.h>
#include <iostream>

using std::cout;
using std::endl;

void sortbubble(int* ar, int length) {
    for (int j = 1; j < length; j++) {
        for (int i = 1; i < length; i++) {
            if (ar[i] < ar[i - 1]) {
                int temp = ar[i];
                    ar[i] = ar[i - 1];
                    ar[i - 1] = temp;
            }
        }
    }
}

int main() {
    int arr[10] = { 23,52,11,16,2,1,24,19,14,9 };
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sortbubble(arr, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    (void)_getch();
    return 0;
}