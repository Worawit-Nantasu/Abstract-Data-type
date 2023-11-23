//นายวรวิทย์ นันทะสุ
//6230300869
#include <iostream>
using namespace std;

int menu() {
    int choose;
    cout << "==================================\n";
    cout << "               MENU               \n";
    cout << "==================================\n";
    cout << "    1)  Print from front \n";
    cout << "    2)  Print from back \n";
    cout << "    3)  Match data base \n";
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}

int main() {
    int choose;
    int i, j, k, l, m, count =1;
    string word;
    char a[5][5] = {
        {'S', 'T', 'L', 'Y', 'R'},
        {'T', 'H', 'E', 'M', 'E'},
        {'A', 'N', 'A', 'G', 'O'},
        {'R', 'O', 'P', 'E', 'S'},
        {'K', 'T', 'T', 'U', 'C'}
    };
    string db[14]={"STLY", "THEME ", "THE" , "THEM" , "HE" , "ME" , 
    "AN" , "GO", "AGO", "ROPE", "OPE", "OGA", "CUT", "OR"};


    while (true) {
        choose = menu();

        switch (choose) {
            case 1:
                for (i = 0; i < 5; i++) {
                    for (j = 0; j < 5; j++) {
                        for (k = j; k < 5; k++) {
                            for (l = j; l <= k; l++) {
                                cout << a[i][l];
                                
                            }
                            cout << " ";    
                        }
                    }
                    cout << endl;
                }
                break;
    //-----------------------------------------------------------------
            case 2:
                for (i = 0; i < 5; i++) {
                    for (j = 4; j >= 0; j--) {
                        for (k = j; k >= 0; k--) {
                            for (l = j; l >= k; l--) {
                                cout << a[i][l];
                            }
                            cout << " ";
                        }
                    }
                    cout << endl;
                }
                break;
    //-----------------------------------------------------------------
            case 3:
             //----------------ตรวจคำ Print from front -------------------

                for (i = 0; i < 5; i++) {
                    for (j = 0; j < 5; j++) {
                        for (k = j; k < 5; k++) {
                            for (l = j; l <= k; l++) {
                                word += a[i][l];
                            }
                            cout << word;

                            for(m=0; m<14; m++){
                                if(word == db[m]){
                                    cout << "          Found " << count++;
                                }else if(word != db[m]){
                                    cout << "";
                                }
                            }
                            cout << endl;
                            word = "";
                        }
                        cout << endl;
                    }
                }
             //----------------ตรวจคำ Print from back -------------------
                for (i = 0; i < 5; i++) {
                    for (j = 4; j >= 0; j--) {
                        for (k = j; k >= 0; k--) {
                            for (l = j; l >= k; l--) {
                                word += a[i][l];
                            }
                            cout << word;
                                           
                            for(m=0; m<14; m++){
                                if(word == db[m]){
                                    cout << "          Found " << count++;
                                }else if(word != db[m]){
                                    cout << "";
                                }
                            }
                            cout << endl;
                            word = "";
                        }
                    }
                }
                cout << endl;
                cout << "Total = " << count-1;
                cout << endl;
    //-----------------------------------------------------------------
            default:
                return 0;
        }
    }

    return 0;
}
