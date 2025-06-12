#include<iostream>
using namespace std;

int getfactorial(int n){
    //base case
    if((n==0)|| (n==1))
    return 1;
    //recursion ka Ans
    int recursionkaAns= getfactorial(n-1);
    //processing
    int finalAns= n * recursionkaAns;
    return finalAns;
}
//print 1 to N --> Head Recursion
void printCounting1(int n){
    //base case
    if(n==0) return ;
    //recursion ka Ans
    printCounting1(n-1);
    //processing
    cout<< n << endl;
}
//print N to 1 -->  Tail Recursion
void printCounting2(int n){
    //base case
    if(n==0)
    return ;
    //processing
    cout << n<<endl;
    //recursion ka Ans
    printCounting2(n-1);
}

//power
int pow(int n){
    //base case
    if(n==0)
    return 1;
    //recursion ka ans
    int recusionkaAns = pow(n-1);
    int finalAns= 2* recusionkaAns;
    return finalAns;
    //processing
}

int fib(int n){
    //base case
    if(n==0 || n==1)
    return n;
    //recursive relation
    int ans= fib(n-1)+ fib(n-2);
    return ans;
    //processing
}

int getSum(int n){
    //base case
    if(n==1)
    return 1;
    //recursive relation
    int ans= n + getSum(n-1);
    return ans;
    //processing
}

int main(){
     

     int fact= getfactorial(10);
     cout << fact << endl;
     
     printCounting1(5);
     cout<<endl;
    // int power= pow(10);
    // cout<<power<<endl;

    // int fibbonaci = fib(9);
    // cout<< fibbonaci<<endl;

    // cout << getSum(6);
    // return 0;
}
