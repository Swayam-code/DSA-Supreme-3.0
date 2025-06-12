#include <iostream>
using namespace std;

int main (){
    //Variables : Named storage location in memory
    //Datatypes : specifies the size and type of data that can be stored in a variable

    //declaring variables
    // int age;
    // cout << age ;

    //defining variables
    int age = 21;
    cout << "My age is " << age << endl; 

    //manipulation or updation
    // age =101;
    // cout << "My age is " << age << endl;

    //int 
    int count = 5;
    //float
    float share = 5.99;
    //char
    char alphabet = 'A';
    //double
    double pi = 3.14;
    //boolean
    bool isMale = true;
    bool isFemale = false;
    bool isChild = 1;
    bool isGirl = 0;

    cout << "Count : " << count << endl;
    cout << "Share : " << share << endl;
    cout << "Alphabet : " << alphabet << endl;
    cout << "Pi : " << pi << endl;
    cout <<"isMale : " << isMale << endl;

    cout << sizeof(count) << endl; //2^16 -1 (int) n= bits
    //signed int : 2^n to -2^n-1
    //unsigned int : 0 to 2^n-1

             
    return 0;
}
