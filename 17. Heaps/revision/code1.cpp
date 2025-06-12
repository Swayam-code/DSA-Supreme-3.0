#include <iostream>
using namespace std;

class Heap{
    public :
        int* arr;
        int capacity;
        int index;

        Heap(int n){
            this->capacity = n;
            arr = new int[n];
            index = 0;
            // jab bhi insert krna hoga, tab index+1 krke insert krdena
            for(int i = 0; i < n; i++){
                arr[i] = 0; // Initialize the array with 0
            }
        }

        void printHeap(){
            for(int i = 1; i<capacity;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

           // TC : O(logn)
        void insert(int val){
            // STEP 1: insert the element normally into the first empty position inside the array
            // STEP 2: then compare the element with the parent and put the element at the right place
            if(index == capacity - 1){
                cout << "overflow"<<endl;
                return;
            }
            // space is available
            // STEP 1: 
            index++;
            arr[index] = val;
            // now put value at right position-> by comparing with parent node
            int i = index; 
            // STEP 2: HEAPIFY
            while(i > 1){ //index ki jgh i pe kaam krenge ab
                int parentIndex = i/2;
                if(arr[parentIndex] < arr[i]){
                    swap(arr[parentIndex],arr[i]);
                    i = parentIndex;
                }
                else{ 
                    //parent ki value already badi hai, no need to do anything
                    break;
                }
            }
        }

        void deleteFromHeap(){
            //replacement
            swap(arr[1], arr[index]); // swap the first element with the last element
            //size decrease
            index--; // decrease the size of the heap
            //heapify
            // heapify(arr, index, 1); // start heapifying from the root node
        }

        //heapify the value present at currIndex

};


 void heapify(int* arr, int n, int currIndex){
            //input
            // n -> number of elements in the array
            int i = currIndex;
            int leftIndex = 2 * i; // left child index
            int rightindex = 2 * i + 1; // right child index

            int largestIndex = i;
            //assuming i per largest value
            //par ho skta hai ki left ya right child ki value badi ho
            //check for left
            if(leftIndex <= n && arr[leftIndex] > arr[largestIndex]){
                largestIndex = leftIndex; // update largest index
            }

            //check for right
            if(rightindex <= n && arr[rightindex] > arr[largestIndex]){
                largestIndex = rightindex; // update largest index
            }
            //if largets value is still i, then no need to do anything
            //if largest value is not i, then swap the values
            if(largestIndex != i){
                swap(arr[i], arr[largestIndex]);
                i = largestIndex; // update i to the largest index
                //now heapify the subtree
                heapify(arr, n, i);
            }
        }

void buildHeap(int* arr, int n){
    // n is the number of elements in the array
    // we will start heapifying from the last non-leaf node
    // last non-leaf node is at index n/2
    for(int i = n/2; i >= 1; i--){
        heapify(arr, n, i); // n-1 because we are using 1-based indexing
    }
}

void HeapSort(int* arr, int n){
    // n -> size of the array
    while( n > 1){
        //delete root element, swap root element with last element
        swap(arr[1], arr[n-1]); 
        //delete the last element
        n--; // decrease the size of the heap
        //heapify the root element
        heapify(arr, n-1, 1); // heapify the root element
    }
}

int main(){

    // Heap pq(6); 
    // 50 40 30 10 20
    int arr [] ={-1, 10,20,30,40,50};
    int n= 6;

    buildHeap(arr,n);
    cout <<endl;
    for(int i = 1; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    HeapSort(arr, n);
    cout << "After Heap Sort: " << endl;
    for(int i = 1; i < n; i++){
        cout << arr[i] << " ";
    }



    // pq.insert(10); // 0 10 0 0 0 0 0 0 0 0
    // // pq.printHeap();
    // pq.insert(20); // 0 20 10 0 0 0 0 0 0 0
    // // pq.printHeap();
    // pq.insert(30); // 0 30 10 20 0 0 0 0 0 0
    // // pq.printHeap();
    // pq.insert(40); // 0 40 30 20 10 0 0 0 0 0
    // // pq.printHeap();
    // pq.insert(50); // 0 50 40 20 10 30 0 0 0 0
    // pq.printHeap();

    // pq.deleteFromHeap(); // Delete the root element (50)
    // pq.printHeap(); 

    // pq.deleteFromHeap(); // Delete the root element (40)
    // pq.printHeap(); 

    // pq.deleteFromHeap(); // Delete the root element (30)
    // pq.printHeap(); 
    // return 0;
}