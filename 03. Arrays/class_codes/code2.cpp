#include <iostream>
using namespace std;

void sortZeroOne(int arr[], int n)
{
    int zeroCount = 0;
    int oneCount = 0;

    for (int i = 0; i < n; i++)
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

    int i = 0;
    for (; i < zeroCount; i++)
    {
        arr[i] = 0;
    }

    for (; i < n; i++)
    {
        arr[i] = 1;
    }
}

void printAllTriplets(int arr[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << arr[i] << "," << arr[j] << "," << arr[k] << endl;
                count++;
            }
        }
    }
    cout << "total triplets printed:" << count << endl;
}

void rotateArray(int arr[], int size, int n)
{
    // size: sizeofArray
    // n: no. of elements to shift
    n = n % size;
    if (n == 0)
    {
        return;
    }

    // step1: copy last n elements into temp array
    int temp[1000];
    int index = 0;
    for (int i = size - n; i < size; i++)
    {
        temp[index] = arr[i];
        index++;
    }

    // step-2: shift array elements by n places
    for (int i = size - 1; i >= 0; i--)
    {
        if (i - n >= 0)
        {
            arr[i] = arr[i - n];
        }
    }

    // step-3: copy elements into original array starting
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void checkThreeSum(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; i++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {

                    cout << arr[i] << "," << arr[j] << "," << arr[k] << endl;
                }
            }
        }
    }
}

bool checkTwoSum(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]+arr[j]== target){
                return true;
            }
        }
    }
    return false;
}

void checkTwoSumAllPairs(int arr[],int n, int target){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]+arr[j]== target){
                cout<<arr[i]<<","<<arr[j]<<endl;
            }
        }
    }
    return;
}

pair<int,int> checkTwoSums(int arr[], int n, int target){
     //assume(-1,-1) as no answer found
     pair<int,int> ans= make_pair(-1,-1);

     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]+arr[j]== target){
                ans.first=arr[i];
                ans.second= arr[j];
                return ans;
            }
        }
    }
    return ans;
}

int main()
{

    int arr[] = {10, 20, 30, 40};
    int size = 4;

    pair<int,int> ans= checkTwoSums(arr,size,70);
    if(ans.first== -1 && ans.second== -1){
        cout<<"pair not found"<<endl;
    }

    else{
        cout<<"pair found :"<<ans.first<<","<<ans.second<<endl;
    }
    // int target= 70;
    
    // bool ans= checkTwoSum(arr,size,70);
    // if(ans== true){
    //     cout<<"pair found"<<endl;
    // }
    // else{
    //     cout<<"pair not found"<<endl;
    // }

    // checkTwoSumAllPairs(arr, size, target);

    //  int n=4;

    //  cout<<"Array before rotating :"<<endl;
    //  for(int i=0;i<size;i++){
    //     cout<<arr[i]<<" ";
    //  }
    //  cout<<endl;

    //  rotateArray(arr,size,n);

    //  cout<<"Array after rotating :"<<endl;
    //  for(int i=0;i<size;i++){
    //     cout<<arr[i]<<" ";
    //  }

    // int arr[]={10,20,30,40};
    // int size= 4;
    // printAllTriplets(arr,size);

    // int arr[]= {0,1,1,0,0,1,1};
    // int size= 7;
    // sortZeroOne(arr,size);

    // for(int i=0;i<size;i++){
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}