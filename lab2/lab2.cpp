#include "lab2.h"
#include <iostream>

using namespace std;

Set::Set(){
    max_size = 100;
    set = new int[max_size];
    size = 0;
}

Set::Set(int x){
    max_size = x;
    set = new int[max_size];
    size = 0;
}
Set::~Set(){
    delete[] set;
}

int* Set::getSet(){
    return set;
}

int Set::getSize(){
    return size;
}

int Set::getMaxSize(){
    return max_size;
}

void Set::printSet(){
    cout << "[ ";
    for (int i = 0; i < size; i++){
        cout << set[i] << " ";
    }
    cout << "]" << endl;
}

void Set::sortingSet(){
    int i = size - 1;
    while (i > 0 && set[i] < set[i - 1])
    {
        swap(set[i], set[i - 1]);
        i--;
    }
    
}
void Set::addElement(int x){
    if (size == max_size){
        cout << "Max size reached !" << endl;
        return;
    }
    for (int i = 0; i < size; i++){
        if (set[i] == x){
            return;
        }
    }
    set[size] = x;
    size++;
    sortingSet();
}
void Set::removeElement(int index){
    if (index >= size){
        return;
    }
    for (int i = index; i < size; i++){
        set[i] = set[i + 1];
    }
    size--;
}
void Set::intersectionSet(Set s){
    int i = 0, j = 0;
    cout << "[ ";
    while (i < size && j < s.getSize()) {
        if (set[i] < s.getSet()[j])
            i++;
        else if (s.getSet()[j] < set[i])
            j++;
        else 
        {
            cout << set[i] << " ";
            i++;
            j++;
        }
    }
    cout << "]" << endl;
}
void Set::unionSet(Set s){
    int i = 0, j = 0;
    cout << "[ ";
    while (i < size && j < s.getSize()) {
        if (set[i] < s.getSet()[j]){
            cout << set[i] << " ";
            i++;
        }
        else if (s.getSet()[j] < set[i]){
            cout << s.getSet()[j] << " ";
        }
        else 
        {
            cout << set[i] << " ";
            i++;
            j++;
        }
    }
    for (i; i < size; i++) cout << set[i] << " ";
    for (j; j < s.getSize(); j++) cout << s.getSet()[j] << " ";
    cout << "]" << endl;
}
void Set::addAllElements(Set s){
    for (int i = 0; i < s.getSize(); i++){
        if (size == max_size){
            cout << "Max size reached !" << endl;
            break;
        }
        addElement(s.getSet()[i]);
    }
}
void Set::removeAllElements(Set s){
    int i = 0, j = 0;
    int *indexArr = new int[max(size, s.getSize())];
    int k = 0;
    while (i < size && j < s.getSize()) {
        if (set[i] < s.getSet()[j])
            i++;
        else if (s.getSet()[j] < set[i])
            j++;
        else 
        {
            indexArr[k] = i;
            k++;
            i++;
            j++;
        }
    }
    for (int k1 = 0; k1 < k; k1++){
        indexArr[k1] -= k1;
        removeElement(indexArr[k1]);
    }
    delete indexArr;
}