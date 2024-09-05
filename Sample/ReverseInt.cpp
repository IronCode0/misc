#include <iostream>
#include <cmath>
using namespace std;
    bool checkRange(int x) {
        if (x<0) x *=(-1);
        if(x < 99999999) return true;
        // check last
        cout << x%1000 << "\n" << x/1000 << endl << endl;
        if (x%1000 < 512) {cout << "code 1" << endl;return false;}
        else if (x/1000 < 7463847) {cout << "code 2"<< endl; return false;}
        cout << x;
        return true;
    }
    int reverse(int x) {
        //if (!checkRange(x)) return 0;
        int Integer;
        long sum=0;
        
        if(x<0){
            //2,147,483,647
            //if ((x*(-1)) > 7463847412) return 0;
            int b=x;
             while(b<0){
                
                 sum=sum*10+b%10;
                b=b/10;
                
                
            }
            
        } else if(x>0){
            //if (x > 7463847412) return 0;
             int a=x;
            while(a>0){
                sum=sum*10+a%10;
                a=a/10;
                
                
            }
        }
        if (x<0) {
             if (sum < -2147483648) return 0;
            else return (int)sum*(-1);
        } else if (x>0) {
            if (sum >  2147483647) return 0;
            else return (int)sum;
        }
        return 0;
    }

int main () {
    cout << reverse(-123) <<"--------------"<<endl;
    cout << reverse(-2147483648) << endl;
}