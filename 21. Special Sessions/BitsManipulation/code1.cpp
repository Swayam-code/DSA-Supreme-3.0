#include<iostream>
using namespace std;

void checkEvenOdd(int n) {
    // Using bitwise AND operator to check if the number is even or odd
    if (n & 1) {
        cout << n << " is Odd" << endl;
    } else {
        cout << n << " is Even" << endl;
    }
}

int getIthBit(int n, int i) {
    // Using bitwise AND operator to get the ith bit of the number
    int mask = 1 << i; 
    int ans = (n & mask); 
    return ans ? 1 : 0; 
}

int setIthBit(int n, int i) {
    // Using bitwise OR operator to set the ith bit of the number
    int mask = 1 << i; 
    return n | mask; 
}

int clearIthBit(int n, int i) {
    // Using bitwise AND operator with negated mask to clear the ith bit of the number
    int mask = ~(1 << i); 
    return n & mask; 
}

int updateIthBit(int n, int i, int target) {
    // Clear the ith bit and then set it to target
    n = clearIthBit(n, i);
    if (target) {
        n = setIthBit(n, i);
    }
    return n;
}

int clearLastIthBits(int n, int i) {
    // Clear the last i bits of the number
    int mask = (-1 << i);
    return n & mask; 
}

int countSetBits(int n) {
    // Count the number of set bits in the number
    int count = 0;
    while (n != 0) {
        count ++;
        n = n & (n - 1); 
    }
    return count;
}

bool checkPowerOfTwo(int n) {
    // Check if the number is a power of two
    // return (n && !(n & (n - 1)));
     int count = countSetBits(n);
    if(count == 1) {
        return true;
    }
    else {
        return false;
    }
}

//HW: exponentiation using bit manipulation
int fastExponentiation(int a, int b){
    int ans = 1;
    while(b>0){
        if(b&1) ans = ans * a;   //odd
        a = a * a;
        b >>= 1;    //b=b/2
    }
    return ans;
}

void clearBitsinRange(int &n, int i, int j) {
    // Clear bits from index i to j (inclusive)
    int a = (1 << i) - 1; 
    int b = (-1 << (j + 1));
    int mask = b | a;
    
    n = n & mask;
}

int main(){
    int n = 16;
    // checkEvenOdd(n);
    // int i = 2;
    // int ithBit = getIthBit(n, i);
    // cout << "The " << i << "th bit of " << n << " is: " << ithBit << endl;
    //10 = 1010 in binary

    // int newNumber = setIthBit(n, i);
    // cout << "Number after setting the " << i << "th bit of " << n << " is: " << newNumber << endl;

    // int clearedNumber = clearIthBit(n, i);
    // cout << "Number after clearing the " << i << "th bit of " << n << " is: " << clearedNumber << endl;

    // int target = 1; 
    // int updatedNumber = updateIthBit(n, i, target);
    // cout << "Number after updating the " << i << "th bit of " << n << " to " << target << " is: " << updatedNumber << endl;

    // int bitsToClear = 2;
    // int clearedBitsNumber = clearLastIthBits(n, bitsToClear);
    // cout << "Number after clearing the last " << bitsToClear << " bits of " << n << " is: " << clearedBitsNumber << endl;

    // int setBitsCount = countSetBits(n);
    // cout << "Number of set bits in " << n << " is: " << setBitsCount << endl;

    // bool isPowerOfTwo = checkPowerOfTwo(n);
    // if (isPowerOfTwo) {
    //     cout << n << " is a power of two." << endl;
    // } else {
    //     cout << n << " is not a power of two." << endl;
    // }

    // int a = 2, b = 10;
    // int result = fastExponentiation(a, b);
    // cout << a << " raised to the power of " << b << " is: " << result << endl;

    int number = 29; // Example number
    int i = 1, j = 3; // Range to clear bits
    cout << "Original number: " << number << endl;
    clearBitsinRange(number, i, j);
    cout << "Number after clearing bits from index " << i << " to " << j << ": " << number << endl;

    return 0;
}