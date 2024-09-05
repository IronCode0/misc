#include<iostream>
#include<string>
using namespace std;

class vechicle {
    
    string name,type,fuel;
    bool used,imported;
    public:
    vechicle(string name,string type,string fuel,bool used,bool imported) {
        this->name=name;
        this->type=type;
        this->fuel=fuel;
        this->used=used;
        this->imported=imported;
    }
    void info() {
        cout << "Name: " << this->name << endl;
        cout << "type: " << this->type << endl;
        cout << "fuel: " << this->fuel << endl;
        cout << this->name;

        if (used)
            cout << " is used and ";
        else
            cout << " new and ";

        if (imported)
            cout << " imported vechicle ";
        else
            cout << " made in India ";

    }
};

int main() {
    vechicle a("Honda accord","car","diesel",0,0);
    vechicle b("Ducati","Bike","petrol",1,1);
    a.info();
    b.info();
    return 0;
}