//given two integers one is a dividend and the other is the divisor, we need to find the quotient when the dividend is divided by the divisor without the use of any "/" and "%" operators
//for example
//input: divident=10, divisor=2
//output:5
//explanation : 10/2 =5

#include<iostream>
using namespace std;

int getQuotient(int dividend, int divisor){
    //search space: (-ve dividend)->(+ve dividend)
    int s = 0;
    int e = dividend;
    int mid = s + ((e-s)>>1);
    int ans = -1;

    while(s<=e){
        if((divisor*mid) == dividend){
            return mid;
        }
        if((divisor*mid) < dividend){
            //ans may/mayn't be quotient
            //store and compute
            ans = mid;
            //move to right side  
            s = mid + 1;
        }
        else{
            //move to left side
            e = mid - 1;
        }
        //me bhul jata hun  
        mid = s + ((e-s)>>1);
    }
    return ans;

}

int main(){
    //dividend = divisor*quotient + remainder
    int dividend = -10;
    int divisor = -3;

    //mission is to get quotient
    int ans  = getQuotient(abs(dividend), abs(divisor));
    if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
        ans = -ans;
    }
    cout<< "final ans: "<<ans<<endl;
    return 0;

}