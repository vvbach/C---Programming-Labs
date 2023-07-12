#include <iostream>
#include <fstream>
#include "lab2.h"

using namespace std;

int main(){
    Set set[100];
    int size = 0;
    int input;
    while (true){
        cout << "Option: " << endl;
        cout << "0: Esc "<< endl;
        cout << "1: Create new set" << endl;
        cout << "2: Add element" << endl;
        cout << "3: Remove element at index" << endl;
        cout << "4: Calculate the intersection of 2 sets" << endl;
        cout << "5: Calculate the union of 2 sets" << endl;
        cout << "6: Add all elements of other set" << endl;
        cout << "7: Remove all elements of other set" << endl;
        cout << "8: Print set" << endl;
        cout << "Choice: "; 
        cin >> input;
        if (input == 0) break;
        else if (input == 1){
            if (size >= 100){
                cout << "Too many sets !" << endl;
                continue;
            }
            int input_size; 
            cout << "Input set size: ";
            cin >> input_size;
            if (input_size <= 0){   
                set[size] = Set();
            }
            else {
                set[size] = Set(input_size);
            }
            size++;
        } 
        else if (input == 2){
            cout << "Choose set to add element: ";
            int set_num; cin >> set_num;
            if(set_num < 1 || set_num > size){
                cout << "Inappropiate input !" << endl;
                continue;
            }
            cout << "Input element: ";
            int element; cin >> element;
            set[set_num - 1].addElement(element);
        }
        else if (input == 3){
            cout << "Choose set to remove element: ";
            int set_num; cin >> set_num;
            if(set_num < 1 || set_num > size){
                cout << "Inappropiate input !" << endl;
                continue;
            }
            cout << "Input index: ";
            int index; cin >> index;
            set[set_num - 1].removeElement(index);
        }
        else if (input == 4){
            cout << "Choose sets to calculate the intersection: ";
            int set_num_1, set_num_2; 
            cin >> set_num_1 >> set_num_2;
            if(set_num_1 < 1 || set_num_1 > size || set_num_2 < 1 || set_num_2 > size){
                cout << "Inappropiate input !" << endl;
                continue;
            }
            set[set_num_1 - 1].intersectionSet(set[set_num_2 - 1]);
        }
        else if (input == 5){
            cout << "Choose sets to calculate the union: ";
            int set_num_1, set_num_2; 
            cin >> set_num_1 >> set_num_2;
            if(set_num_1 < 1 || set_num_1 > size || set_num_2 < 1 || set_num_2 > size){
                cout << "Inappropiate input !" << endl;
                continue;
            }
            set[set_num_1 - 1].unionSet(set[set_num_2 - 1]);
        }
        else if (input == 6){
            cout << "Choose sets to add all the elements from 2nd to 1st set: ";
            int set_num_1, set_num_2; 
            cin >> set_num_1 >> set_num_2;
            if(set_num_1 < 1 || set_num_1 > size || set_num_2 < 1 || set_num_2 > size){
                cout << "Inappropiate input !" << endl;
                continue;
            }
            set[set_num_1 - 1].addAllElements(set[set_num_2 - 1]);
        }
        else if (input == 7){
            cout << "Choose sets to remove all the elements from 2nd to 1st set: ";
            int set_num_1, set_num_2; 
            cin >> set_num_1 >> set_num_2;
            if(set_num_1 < 1 || set_num_1 > size || set_num_2 < 1 || set_num_2 > size){
                cout << "Inappropiate input !" << endl;
                continue;
            }
            set[set_num_1 - 1].removeAllElements(set[set_num_2 - 1]);
        }
        else if (input == 8){
            cout << "Print set: ";
            int set_num; 
            cin >> set_num;
            if(set_num < 1 || set_num > size){
                cout << "Inappropiate input !" << endl;
                continue;
            }
            set[set_num - 1].printSet();
        }
        
    }
}