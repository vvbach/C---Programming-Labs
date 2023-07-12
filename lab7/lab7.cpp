#include <iostream>
#include "CircularBuffer.cpp"
#include <algorithm>

using namespace std;

int main(){
    CircularBuffer<int> v(10);
    for (int i = 0; i < 10; i++) 
    {
        v.push_back(i);
    }
    v.resize(6);
    v.push_front(10);
    v.insert(123, v.begin() + 4);
    cout << v.getCapacity() << " " << v.getSize() << endl;
    for (auto i = v.begin(); i != v.end(); i++){
        cout << *i << endl;
    }
    cout << *(v.end()) << endl;
    cout << v.getCapacity() << " " << v.getSize() << endl;
}