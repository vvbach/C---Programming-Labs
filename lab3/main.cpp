#include <iostream>
#include "lab3.h"

using namespace std;

int main(){
    int input;
    Matrix m1, m2;
    Queue q;
    while (true){
        cout << "Option: " << endl;
        cout << "0: Esc "<< endl;
        cout << "1: Input matrix 1" << endl;
        cout << "2: Input matrix 2" << endl;
        cout << "3: Add 2 matrices" << endl;
        cout << "4: Subtract 2 matrices" << endl;
        cout << "5: Multiply 2 matrices" << endl;
        cout << "6: Multiply matrix with a number" << endl;
        cout << "7: Compare 2 matrices" << endl;
        cout << "8: Push into queue" << endl;
        cout << "9: Pop queue" << endl;
        cout << "Choice: ";  
        cin >> input;
        if (input == 0) break;
        else if (input == 1){
            m1.inputMatrix();
        } 
        else if (input == 2){
            m2.inputMatrix();
        }
        else if (input == 3){
            Matrix m3 = m1 + m2;
            m3.printMatrix();
        }
        else if (input == 4){
            Matrix m3 = m1 - m2;
            m3.printMatrix();
        }
        else if (input == 5){
            Matrix m3 = m1 * m2;
            m3.printMatrix();
        }
        else if (input == 6){
            cout << "1st or 2nd ?: ";
            int choice; cin >> choice;
            cout << "Input number: ";
            double num; cin >> num;
            Matrix m3;
            if (input == 1){
                m3 = m1 * num;
            } else {
                m3 = m2 * num;
            }
            m3.printMatrix();
        }
        else if (input == 7){
            cout << "Choose operator(< > == !=): ";
            int choice; cin >> choice;
            switch (choice)
            {
            case 1:
                cout << (m1 < m2);
                break;
            case 2:
                cout << (m1 > m2);
                break;
            case 3:
                cout << (m1 == m2);
                break;
            case 4:
                cout << (m1 != m2);
                break;
            default:
                break;
            }
        }
        else if (input == 8){
            cout << "Input num: ";
            int num; cin >> num;
            q << num;
        }
        else if (input == 9){
            int num;
            q >> num;
            cout << num << endl;
        }
    }
}