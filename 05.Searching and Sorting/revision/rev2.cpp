#include<iostream>
using namespace std;

int mySqrt(int x) {
    int s = 0;
    int e= x;
    long long int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e){
        //happy case
        long long int prod = mid*mid;
        if(prod == x){
            return mid;
        }
        if(prod <x){
            //store and compute
            ans = mid;
            s= mid+1;
        }
        else{
            e = mid-1;
        }
        //bhul jata hun
        mid =s+(e-s)/2;
    }
    double sqrtAns = (double)ans;

    //precision upto how many didgits
    int precision ;
    cout << "Enter the precision: " << endl;
    cin >> precision;
    double factor = 1;

    for(int i=0; i<precision; i++){
        factor = factor/10;
        for(int n=0; n<=9;n++){
            double toAdd =  n*factor;
            if(sqrtAns*sqrtAns <= x){
                sqrtAns += toAdd;
            }
            else{
                break;
            }
        }
    }
    return sqrtAns;
}

int main (){
    int num =54;

    double ans = mySqrt(num);
    cout<< ans <<endl;
}