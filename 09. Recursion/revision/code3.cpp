#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printSubSequences( string str, int i, string output, vector<string>& ans){
    //base case
    if(i == str.length()){
        // cout<< output << endl;
        ans.push_back(output);
        return;
    }
    //1 case khud karunga
    char ch = str[i];
    //include
    printSubSequences(str,i+1,output+ch,ans);
    //exclude
    printSubSequences(str,i+1,output, ans);

}

//H.W.-1 : SORTED IN DESCENDING ORDER
int checkSortedDescending(int arr[],int n, int index){
    //base case
    if(index == n-1) {
        return true; //single element array treated as SORTED
    }

    bool currAns = false;
    bool recursionKaAns = false;

    //1 case solve kar do
    if(arr[index+1] < arr[index]){
        currAns = true;
    }

    //recursion ka Ans
    recursionKaAns = checkSortedDescending(arr, n, index+1);
    
    //processing
    return currAns && recursionKaAns;
    
}

int checkSorted(int arr[],int n, int index){
    //base case
    if(index == n-1) {
        return true; //single element array treated as SORTED
    }

    bool currAns = false;
    bool recursionKaAns = false;

    //1 case solve kar do
    if(arr[index+1] > arr[index]){
        currAns = true;
    }

    //recursion ka Ans
    recursionKaAns = checkSorted(arr, n, index+1);
    
    //processing
    return currAns && recursionKaAns;
    
}

int main (){
    
    string str = "abc";
    string output = "";
    int index = 0;
    
    vector<string> ans;
    printSubSequences(str, index, output, ans);
    cout << "All possible subsequences are : " << endl;
    for(auto num : ans){
        cout << num << endl;
    } 
    cout << "Total number of subsequences are : " << ans.size() << endl;  


    // int arr[] = {1,2,3,4,5,600,6,7,8,9};
    // int arr[] = {70,60,50,40,45,30,20,10};
    // int size = sizeof(arr)/sizeof(int);
    // int index = 0;

    // bool ans = checkSortedDescending(arr, size, index);
    // cout << "Array is sorted in descending order or not : " << ans << endl;

    // bool ans = checkSorted(arr, size, index);
    // cout << "Array is sorted or not : " << ans << endl;

    return 0;
}