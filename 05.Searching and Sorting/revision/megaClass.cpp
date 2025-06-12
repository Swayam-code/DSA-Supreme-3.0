#include<iostream>
using namespace std;

int mySqrt (int n){
   int s = 0;
   int e = n;
   int mid = s + (e-s)/2;
   int ans = 0;

   while(s<=e){
         //happy case
         long long int prod = mid*mid;
         if(prod <= n){
            //store and compute
            ans = mid;
            s = mid + 1; //go to right side
        }
        else{
            e = mid - 1; //go to left side
        }
         //bhul jata hun
         mid = s + (e-s)/2;
   }
   return ans;
}

//Method-1
double myPrecisionSqrt(int n){
    double sqrt = mySqrt(n);
    int precision;
    //precision upto how many digits
    cout << "Enter the precision: " ;
    cin >> precision;
    double step = 0.1;

    while(precision--){
        double j = sqrt; //7->7.0
        while(j*j <= n){
            //store and compute
            sqrt = j; 
            j += step; //7.0->7.1
        }
        //after this while loop i got 1 precision ans
        step /= 10;
    }
    return sqrt;
    //T.C -> O(log(n) + precision)
    //S.C -> O(1)
}

//Method-2
double BSPrecisionSqrt(int n){
    double s = 0;
    double e = n;
    double mid = s + (e-s)/2;
    double ans = 0;

    while(e-s >= 0.0000000001){
        //happy case
        double prod = mid*mid;
        if(prod <= n){
            //store and compute
            ans = mid;
            s = mid ; //go to right side
        }
        else{
            e = mid ; //go to left side
        }
        //bhul jata hun
        mid = s + (e-s)/2;
    }
    return ans;
    //T.C.-> O(log(n) )
    //S.C.-> O(1)
}

int main(){
     
    int num = 63;
    double ans = BSPrecisionSqrt(num);
    printf("Precison Sqrt : %.10f \n", ans);

    // double ans = myPrecisionSqrt(num);
    // cout << ans << endl;
    //cout only prints upto 5 precision   
    // printf("Precison Sqrt : %.13f \n", ans);
}