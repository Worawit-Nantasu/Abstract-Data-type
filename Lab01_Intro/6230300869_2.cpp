//นายวรวิทย์ นันทะสุ
//6230300869
#include <iostream>
using namespace std;

int menu()
{
    int choose;
    cout << "===============MENU===============\n";
    cout << "    1)  Insert the frist value \n";
    cout << "    2)  Insert front \n";
    cout << "    3)  Insert last\n";
    cout << "    4)  Insert middle\n";
    cout << "    5)  Exit\n";
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}
int main()
{
    int choose, i, firstValue, frontValue, lastValue, 
    middleValue, insertMiddle, exitValue, count=0;
    const int SIZE = 10;
    int numbers[SIZE];
    

    while (true)
    {
        choose=menu();
        switch (choose)
        {
        case 1:
            if (count < SIZE){
                cout << "Enter data : ";
                cin >> firstValue;
                
                numbers[count++] = firstValue;
                cout << "Data in list = " ;
                for(i=0; i<count;++i){
                    cout << numbers[i] << " ";
                }
                cout << endl;
            }
            break;
    //-----------------------------------------------------------------------------
        case 2:
            if(count < SIZE){
                cout << "Enter data : ";
                cin >> frontValue;
                cout << "Move = " << count << " Position\n"; //จำนวนตำแหน่งที่ย้าย
                //-----------------แสดงจำนวนใน Array ก่อนย้ายตำแหน่ง------------------
                cout << "Data move = ";
                for(i=0; i<count; ++i){ 
                    cout << numbers[i] << " ";
                }
                cout << endl;
                //------------------ย้ายตำแหน่งของตัวเลข------------------------------
                for(i=count; i>=1; --i){
                    numbers[i] = numbers[i - 1];
                }
                //------------------วาง input ล่าสุดทับลงไป---------------------------
                numbers[0] = frontValue;
                ++count;
                //----------------- Show all data in list--------------------------
                cout << "Data in list = ";
                for (i = 0; i < count; ++i)
                {
                    cout << numbers[i] << " ";
                }
                cout << endl;
            }
            break;
    //-----------------------------------------------------------------------------
        case 3:
            if(count < SIZE){
                cout << "Enter data : ";
                cin >> lastValue;
                numbers[count++] = lastValue;
                cout << "Move = 0 Position.\n";
                cout << "Data move = Nothing.\n";
                cout << "Data in list = ";
                for (i = 0; i < count; ++i)
                {
                    cout << numbers[i] << " ";
                }
                cout << endl;
            }
            break;
    //-----------------------------------------------------------------------------
        case 4:
            if(count < SIZE){
                cout << "Enter data : ";
                cin >> middleValue;
                insertMiddle = count/2;
                
                cout << "Move = " << count - insertMiddle << " Position\n";
                //------------------ย้ายตัวเลขที่อยู่หลัง Middle ให้ขยับออกไปอีก-------------
                for (i = count; i > insertMiddle; --i){
                    numbers[i] = numbers[i - 1];
                }
                numbers[insertMiddle] = middleValue;
                ++count; //5

                cout << "Data move = ";
                for (i = insertMiddle + 1; i < count; ++i)
                {
                    cout << numbers[i] << " ";
                }
                cout << endl;

                cout << "Data in list = ";
                for (i = 0; i < count; ++i)
                {
                    cout << numbers[i] << " ";
                }
                cout << endl;
            }
            break;
    //-----------------------------------------------------------------------------
            case 5:
                cout << "Enter : ";
                cin >> exitValue;
                if(exitValue == -1){
                    cout << "Bye\n"; 
                    return 0;
                }
                break;
    //-----------------------------------------------------------------------------       
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}