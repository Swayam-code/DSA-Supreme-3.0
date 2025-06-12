#include<iostream>
using namespace std;

int getSum(int n){
    //base-case
    if(n==0){
        return 0;
    }
    //recursion-case
    int recursionkaAns = getSum(n-1);
    
    //processing
    int myAns = n + recursionkaAns;
    return myAns;                                                          
}

int fibonnacci(int n){
    //base-case
    if(n==0 || n==1){
        return n;
    }
    //recursion-case
    int recursionkaAns = fibonnacci(n-1) + fibonnacci(n-2);
    
    //processing
    int myAns = recursionkaAns;
    return myAns;                                                       
}

int powOf2(int n){
    //base-case
    if(n==0){
        return 1; // 2^0 = 1
    }
    //recursion-case
    int recursionkaAns = powOf2(n-1);
    
    //processing
    int myAns = 2 * recursionkaAns;
    return myAns;    
    //T.C. :  O(n)
    //S.C. :  O(n) (due to recursion stack)                                                   
}

//Print counting from 1 to n
void printCounting1 (int n){
    //base-case
    if(n==0){
        return;
    }
    //recursion-case
    printCounting1(n-1);
    
    //processing
    cout<<n<<" ";
}

void printCounting2 (int n){
    //base-case
    if(n==0){
        return;
    }
    //processing
    cout<<n<<" ";
    
    //recursion-case
    printCounting2(n-1);
}

int getFactorial(int n){
    //base-case
    if(n==0 || n==1){
        return 1;
    }
    //recursion-case
    int recursionkaAns = getFactorial(n-1);
    
    //processing
    int myAns = n * recursionkaAns;
    return myAns;                                                          
}

int main(){
    
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout << "Sum of first " << n << " numbers is: " << getSum(n) << endl;
    
    cout << "Fibonacci of " << n << " is: " << fibonnacci(n) << endl;

    // int ans  = powOf2(n);
    // cout<<"2^"<<n<<" is: "<<ans<<endl;

    // printCounting1(n);
    // cout<<endl;
    // printCounting2(n);
    // cout<<endl;

    // int ans = getFactorial(n);
    // cout<<"Factorial of "<<n<<" is: "<<ans<<endl;

    
    return 0;
}