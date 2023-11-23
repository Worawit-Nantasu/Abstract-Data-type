//นายวรวิทย์ นันทะสุ
//6230300869
#include <iostream>
using namespace std;

int main()
{
    int i, j, k, rowValue;
    char a[5][5] = {
        {'S','T','L','Y','R'},
        {'T','H','E','M','E'},
        {'A','N','A','G','O'},
        {'R','O','P','E','S'},
        {'K','T','T','U','C'}};

    cout << "Input : ";
    cin >> rowValue; 

    for(i=rowValue-1; i<rowValue; i++){
        for(j=0; j<5; j++){
            for(k=0; k<=j; k++){
                cout << a[i][k];
            }
            cout << " ";
        }
        cout << endl;
    }    
}
