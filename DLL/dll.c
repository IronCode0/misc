// https://stackoverflow.com/questions/847396/compile-a-dll-in-c-c-then-call-it-from-another-program
// gcc -c -DBUILD_DLL dll.c
// gcc -shared -o mydll.dll dll.o -Wl,--out-implib,libmessage.a
//#include "dll.h"


int add2(int num){
   return num + 2;
}

int mult(int num1, int num2){
   int product;
   product = num1 * num2;
   return product;
}


