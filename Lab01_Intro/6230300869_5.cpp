//นายวรวิทย์ นันทะสุ
//6230300869
#include <iostream>
using namespace std;

int main() {
    int n ;
    cout << "Enter: ";
    cin >> n;

    if (n > 15) {
        cout << "Error, more than 15" << endl;
        return 0;
    } else if (n == 0 || n == 1) {
        cout << "Fibonacci of " << n << " = 1" << endl;
        return 0;
    }

    int Xn = 0; 
    int Xn0 = 1; 
    int Xn1 = 1; 

    for (int i = 2; i <= n; i++){
        Xn = Xn0 + Xn1;
        Xn1 = Xn0;
        Xn0 = Xn;
    }

    cout << "Fibonacci of " << n << " = " << Xn << endl;

    return 0;
}
