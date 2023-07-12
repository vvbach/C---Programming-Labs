#include <iostream>
#include <vector>
#include "lab6.cpp"

using namespace std;

bool predicate_01(int a){
    if (a <= 6) return true;
    return false;
}

bool predicate_02(Point p){
    return p == Point(1, 6);
}

int main(){
    vector<int> v1 {2, 3, 4, 5, 6, 7, 8};
    vector<Point> p1;
    p1.push_back(Point(1, 4));
    p1.push_back(Point(3, 4));
    p1.push_back(Point(1, 6));
    p1.push_back(Point(6, 2));
    p1.push_back(Point(5, 5));

    cout << all_of(v1.begin(), v1.end(), predicate_01) << endl;
    cout << is_partition(v1.begin(), v1.end(), predicate_01) << endl;
    cout << find_backward(v1.begin(), v1.end(), 4) << endl;

    cout << all_of(p1.begin(), p1.end(), predicate_02) << endl;
    cout << is_partition(p1.begin(), p1.end(), predicate_02) << endl;
    cout << find_backward(p1.begin(), p1.end(), Point(3, 8)) << endl;
}