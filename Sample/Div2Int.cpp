#include <iostream>
#include <vector>
using namespace std;
// to use yhis code in leetcode replace '_abs64' with 'fabsf64'
class Div {
    bool sign;
private:
    int sw(int a) {
        if (a == -2147483648) return 2147483647;
        else return abs(a);
    }
    int sw(int a,bool is64) {
        if (a == -2147483648) return 2147483647;
        else return abs(a);
    }
    bool sg(int a, int b) {
        if ((a<0) && (b<0)) return true;
        if ((a<0) || (b<0)) return false;
        return true;
    }
    int get_sg(long int a) {
        if (sign) return sw(a);
        return -a;
    }
public:
    int divide(int dividend, int divisor) {
        sign = sg(dividend, divisor);
        int count =0;
        if (abs(divisor) == 1) {
            return get_sg(_abs64(dividend));
        }
        if (_abs64((long)divisor) > _abs64((long)dividend)) return 0;
        int sum=sw(dividend);
        divisor = sw(divisor);
        while(sum>=divisor){
            sum -=divisor;
            count++;
        }
        if (dividend == -2147483648 && !sign) count++;
        return get_sg(count);
        return 0;
    }
};
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negative = (dividend > 0) ^ (divisor > 0);
        if(dividend == -2147483648 && divisor == -1) return 2147483647;
        if(dividend > 0) dividend = -dividend;
        if(divisor > 0) divisor = -divisor; 
        int value = sub_divide(dividend, divisor);
        return negative ? value : -value;
    }
    
private:
    int sub_divide(int dividend, int divisor) {
        if(dividend > divisor) return 0;
        int value = -1;
        int sum = divisor;
        while(sum >= dividend - sum) {
            value += value;
            sum += sum;
            if(sum > 0) break;
        }
        return value + sub_divide(dividend-sum, divisor);
    }
};

int main() {
    Solution a;
    Div b;
    vector<vector<int>> arr={
         {-1010369383 , -2147483648 , 0           }
        ,{-2147483648 ,  1          , -2147483648 }
        ,{-2147483648 , -1          ,  2147483647 }
        ,{ 2147483647 ,  1          ,  2147483647 }
        ,{-1          ,  1          , -1          }
        ,{ 2147483647 , -2147483648 ,  0          }
        ,{-2147483648 ,  2          , -1073741824 }
        ,{-1          ,  1          , -1          }
        ,{ 10         ,  3          ,  3          }
        ,{-2147483648 ,  1          , -2147483648 }
        ,{ 2147483647 ,  1          ,  2147483647 }
        ,{ 1          , -1          , -1          }
        ,{-2147483648 , -3          ,  715827882  }
        ,{-2147483648 ,  4          , -536870912  }
    };

    int x,y;
    for(vector<int> p : arr)  {
        cout << "dividing " << p[0] << " by " << p[1] << endl;
        y = b.divide(p[0], p[1]);
        cout << "Output = " << y << endl;
        if (y != p[2]) {
            cout << "incorrect solution is " << p[2] << endl;
        }
        cout << "----------------" << endl;
    }
    return 0;
}
