#pragma once

#include <iostream>

using namespace std;

class Exception {
private:
    string msg;
public:
    Exception(string msg) : msg(msg){};
    string getMessage() {return msg;};
};