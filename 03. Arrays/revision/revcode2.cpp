#include <iostream>
#include <algorithm>
using namespace std;

void print(int arr[], int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << arr[index] << " ";
    }
    cout << endl;
}

int findUniqueNumber(int arr[], int size)
{
    // Method-1: Using XOR operator
    //  int n= size;
    //  int ans = 0;
    //  for(int i =0;i<n;i++){
    //      ans = ans ^ arr[i];
    //  }
    //  return ans;

    // Method-2 : Using Mathematical formula
    //  uniqueNumber = 2 * (sum of unique elements) - (sum of all elements)
    int n = size;
    int sumOfArray = 0;
    int sumOfUnique = 0;

    for (int i = 0; i < size; i++)
    {
        sumOfArray += arr[i];

        bool isUnique = true;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isUnique = false;
                break;
            }
        }

        if (isUnique)
        {
            sumOfUnique += arr[i];
        }
    }
    return 2 * sumOfUnique - sumOfArray;
}

void sortZeroesandOnes(int arr[], int size)
{
    // Method-1:
    int zeroCount = 0;
    int oneCount = 0;
    // counting
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zeroCount++;
        }
        if (arr[i] == 1)
        {
            oneCount++;
        }
    }
    // insertion
    fill(arr, arr + zeroCount, 0);
    fill(arr + zeroCount, arr + size, 1);

    // for(int i=0;i<zeroCount;i++){
    //     arr[i] = 0;
    // }
    // for(int i=zeroCount;i<size;i++){
    //     arr[i] = 1;
    // }

    // Method-2: Using 2 pointer approach
    //  int n = size;
    //  int i = 0;
    //  int j = n - 1;

    // while (i <= j) {
    //     if (arr[i] == 0) {
    //         i++;
    //     } else if (arr[j] == 1) {
    //         j--;
    //     } else {
    //         swap(arr[i], arr[j]);
    //         i++;
    //         j--;
    //     }
    // }
    // cout << endl;

    // Method-3 :sorting using STL
    //  sort(arr, arr+size);
}

void printAllPairs(int arr[], int size)
{
    // printAllPairs
    //  for (int i = 0; i < size; i++) {
    //      for (int j = 0; j < size; j++) {
    //          cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
    //      }
    //  }
    // printLowerTriangularPairs
    //  for(int i = 0; i < size; i++) {
    //      for (int j = i; j < size; j++) {
    //              cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
    //      }
    //  }
    //  cout << endl;
    // printLowerTriangularPairs
    //  for(int i = 0; i < size; i++) {
    //      for (int j = 0; j <i; j++) {
    //              cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
    //      }
    //  }

    // AllpPairsinReverseOrder
    //  for(int i = 0; i < size; i++) {
    //      for (int j = size-1; j >=0; j--) {
    //              cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
    //      }
    //  }
    
    //printLowerTriangularMatrixin Reverse Order
    // for (int i = 0; i < size; i++){
    //     for (int j = size - 1; j >=i; j--){
    //         cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
    //     }
    // } 
   
    //printLowerTriangularMatrix-without diagonal
    // for (int i = 0; i < size; i++){
    //     for (int j = i+1; j <size; j++){
    //         cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
    //     }
    // } 

}

pair<int,int> checkTwoSum(int arr[], int n , int target)
{
    //assuming (-1,-1) as default value
    pair<int,int> ans= make_pair(-1,-1);
    //check all pairs
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                ans.first = arr[i];
                ans.second = arr[j];
                return ans;
            }
        }
    }
    //no ans found since we exited the loop
    return ans;
}

void printAllTriplets(int arr[], int size)
{
    // printAllTriplets
    //Time complexity: O(n^3)
    // Space complexity: O(1)
    int count = 0;
     for(int i = 0; i < size; i++) {
         for (int j = 0; j < size; j++) {
             for (int k = 0; k < size; k++) {
                 cout << "(" << arr[i] << ", " << arr[j] << ", " << arr[k] << ")" << endl;
                 count++;
             }
         }
     }
     cout << "Total number of triplets: " << count << endl;
    cout << endl;
}

bool checkThreeSum (int arr[], int n, int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==target){
                    //ans found
                    cout << "(" << arr[i] << ", " << arr[j] << ", " << arr[k] << ")" << endl;
                }
            }
        }
    }
}

void rotateArray(int arr[], int size, int n){
    //size = size of the array
    //n = number of positions to shift
    int n =n % size; // to handle cases where shift > size
    if (n == 0){
        return; // no rotatrion needed
    }
    //Step-1: copy last k elements to a temporary array
    int temp[10000];
    int index = 0;
    for(int i = size - n; i < size; i++){
        temp[index] = arr[i];
        index++;
    }
    //Step-2: shift elements in original array to the finalShift position
    for(int i =size-1; i>=0;i--){
        if(i-n >= 0){
            arr[i] = arr[i-n];
        }
        
    }

    //step-3: copy elements from temp array to original array
    for(int i = 0; i < n; i++){
        arr[i] = temp[i];
    }
}

// HW-2: flip 0's and 1's in an array
void flipZeroesandOnes(int arr[], int size)
{
    // Method-1: Using 1's complement operator
    int n = size;
    for (int i = 0; i < n; i++)
    {
        arr[i] = ~arr[i] & 1; // 1's complement operator
    }
    cout << endl;
}

void flipandConverttoSigned(int arr[], int size)
{
    int n = size;
    for (int i = 0; i < n; i++)
    {
        arr[i] = ~arr[i] & 1; // 1's complement operator

        if (arr[i] == 1)
        {
            arr[i] = ~arr[i] + 1; // 2's complement operator
        }
    }
    cout << endl;
}

int main()
{   
    
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;
    //cyclically rotate array by 2 places
    int shift =5;
    cout << "Before rotation: ";
    print(arr,size);
    cout<<endl;
    cout << "After rotation: ";
    rotateArray(arr,size,shift);
    print(arr,size);
    


    // int arr[] = {10, 20, 30, 40};
    // int size = 4;
    // int target = 70;
    // checkThreeSum(arr,size,target);
    // printAllTriplets(arr, size);
    
    // int arr[]={10,5,20,15,30};
    // int size= 5;
    // int target = 35;

    // pair<int,int> ans = checkTwoSum(arr,size,target);
    // if(ans.first ==-1 && ans.second ==-1){
    //     cout << "Pair not found" << endl;
    // }else{  
    //     cout << "Pair found: " << "("<<ans.first << "," << ans.second << ")" << endl;
    // }

    // int arr[] = {10, 20, 30, 40};
    // int size = 4;
    // printAllPairs(arr, size);

    // int arr[] ={0,1,0,1,0,1,0,1};
    // int size = 8;

    // sortZeroesandOnes(arr,size);
    // print(arr,size);

    // flipZeroesandOnes(arr,size);
    // flipandConverttoSigned(arr,size);
    // print(arr,size);

    // int arr[] ={2,4,2,1,1,2};
    // int size = 5;

    // int ans = findUniqueNumber(arr,size);
    // cout << "Unique number is : " << ans << endl;

    return 0;
}