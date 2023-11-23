#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int numbers[SIZE];

    cout << "Enter : ";

    for (int i = 0; i < SIZE; ++i) {
        cin >> numbers[i];

        if (i > 0 && numbers[i] <= numbers[i - 1]) {
            cout << "Invalid input!" << endl;
            return 0;
        }
    }
//--------------------------------------------------------
    cout << endl;
    cout << "(index)| ";
    for (int i = 0; i < SIZE; ++i) {
        cout << i << " ";
    }
    cout << endl;
    cout << "-------|-----------";

    cout << endl << "(value)| ";
    for (int i = 0; i < SIZE; ++i) {
        cout << numbers[i] << " ";
    }
//--------------------------------------------------------
    cout << endl;

    int newValue;
    cout << endl;
    cout << "Enter value : ";
    cin >> newValue;

    int index = -1;

    for (int i = 0; i < SIZE; ++i) {
        if (numbers[i] > newValue) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "No number" << endl;
    } else {
        cout << "index = " << index << endl;
    }

    return 0;
}
