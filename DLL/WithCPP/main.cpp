#include "chat.h"
#include "calc.h"
//#include <string>
#include <iostream>
using namespace std;
int main(void) {
    chat("Hello world");
    double rslt = add(2.5, 2.5);
    cout << "add result: " << rslt << endl;
    rslt = multiply(3.5,2);
    cout << "multiply result: " << rslt << endl;
    return 0;
}