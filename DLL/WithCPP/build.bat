g++ -c calc.cpp -o calc.o
ar rcs libcalc.a calc.o

g++ -c chat.cpp -o chat.o
ar rcs libchat.a chat.o

g++ -c main.cpp -o main.o
g++ -o main.exe main.o -L. -lchat -lcalc

