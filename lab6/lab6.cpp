#include <iostream>

using namespace std;

template<class Iter, class Type>
bool all_of(Iter begin, Iter end, bool (*func)(Type element)){
    for (auto i = begin; i != end; i++){
        if (!func(*i)) return false;
    }
    return true;
}

template<class Iter, class Type>
bool is_partition(Iter begin, Iter end, bool (*func)(Type element)){
    auto i = begin;
    int bool_counter = 0;
    bool prev = func(*i);
    i++;
    for (i; i != end; i++){
        if (func(*i) != prev){
            bool_counter++;
            prev = !prev;
        } 
    }
    return (bool_counter == 1 ? true : false);
}

template<class Iter, class Type>
int find_backward(Iter begin, Iter end, const Type value){
    int index = -1;
    for (auto i = end; i != begin; i--){
        index++;
        if (*i == value){
            return index;
        }
    }
    return -1;
}

class Point {
private:
    double x, y;
public:
    Point(double x, double y) : x(x), y(y){}
    bool operator==(const Point& p){
        return (x == p.x) && (y == p.y);
    }
};