#include<iostream>
#include<vector>
using namespace std;

vector<int> findTwoComplement(vector<int> binary) {
    int n = binary.size();
    vector<int> twoComplement(n);
    
    // Step 1: Find the 1's complement // Invert the bits
    for (int i =n-1; i >= 0; i--) {
        twoComplement[i] = (binary[i] == 0) ? 1 : 0;
    }
    
    // Step 2: Add 1 to the 1's complement
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        int sum = twoComplement[i] + carry;
        twoComplement[i] = sum % 2; // Update the bit
        carry = sum / 2; // Carry for the next bit
    }
    if(carry ==1){
        if (carry == 1) {
        twoComplement[0] = 1; // If carry is still 1, we need to add it to the first bit
        }
    }
    
    return twoComplement;
}

vector<int> findTwoComplement2 (vector<int> binary) { //without considering extra bit
    int n = binary.size();
    vector<int> twoComplement(n);
    
    // Step 1: Find the 1's complement // Invert the bits
    for (int i =n-1; i >= 0; i--) {
        twoComplement[i] = (binary[i] == 0) ? 1 : 0;
    }
    
    // Step 2: Add 1 to the 1's complement
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        int sum = twoComplement[i] + carry;
        twoComplement[i] = sum % 2; // Update the bit
        carry = sum / 2; // Carry for the next bit
    }
    
    return twoComplement;
}

int main(){
    vector<int> binary ={0,0,1,0,1,0,1,1,0}; // Example binary number -> 111010110
    vector<int> twoComps = findTwoComplement(binary);
    // vector<int> twoComps = findTwoComplement2(binary);
    cout << "The 2's complement of the binary number is: ";
    for(int i=0; i<twoComps.size(); i++){
        cout<<twoComps[i];
    }
    cout << endl;

    return 0;           
}