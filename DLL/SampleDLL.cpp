//#include "StdAfx.h"
#include "SampleDLL.h"
#include <iostream>
 
using namespace std; 
 
HelloDLL::HelloDLL(void)
{
}
 
HelloDLL::~HelloDLL(void)
{
}
 
void HelloDLL::hello()
{
    cout << "Hello World of DLL" << endl;
}
 
void HelloDLL::helloStatic()
{
    cout << "Hello World of DL" << endl;
}