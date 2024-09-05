#include "dll.h"
void pipcomand(string strCmd) {
    std::array<char,80> buffer;
    FILE *pipe = popen(strCmd.c_str(),"r");
    if(!pipe) std::cerr << "Cannot open file" << std::endl;
    int c=0;
    while(fgets(buffer.data(),80,pipe) != NULL) {
        c++;
        std::cout << c << "\t" << buffer.data();
    }
    pclose(pipe);
}
void say(string str) {
    std::cout << "I typed: "<< str << std::endl;
}