#include<iostream>
using namespace std;

class MaxHeap{
    public:
    int *arr;
    int capacity;
    int size;

    MaxHeap(int capacity){
        this->arr = new int[capacity]();  //using "()" in last to initialise all values in array with 0
        this->capacity = capacity;

        //size = current number of elements in heap
        this->size = 0;
    }

    void insert(int val){
        //Check Overflow
        if(size == capacity){
            cout<<"Heap Overflow"<<endl;
            return;
        }

        //Size increases by 1
        size++;
        int index = size;
        arr[index] = val;

        //Heapify : take value to correct position
        while(index > 1){
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    int deleteFromHeap(){
        int deletedVal = arr[1];

        //Step 1 : Replacement
        arr[1] = arr[size];

        //Step 2 : Heapify
        //Last element to delete kro from it's original position
        size--;

        int index = 1;

        while(index < size){
            int leftChildIndex = 2*index;
            int rightChildIndex = 2*index + 1;

            //Find sabse bda element
            int largestKaIndex = index; //Assume for now, niche change hojaega

            //Check left & right child
            if(leftChildIndex <= size && arr[largestKaIndex] < arr[leftChildIndex]){
                largestKaIndex = leftChildIndex;
            }
            if(rightChildIndex <= size && arr[largestKaIndex] < arr[rightChildIndex]){
                largestKaIndex = rightChildIndex;
            }

            //No change : Heapification Done
            if(index == largestKaIndex){
                break;
            }
            else{
                swap(arr[index], arr[largestKaIndex]);
                index = largestKaIndex;
            }
        }

        return deletedVal;

    }

    void printHeap(){
        cout<<"Printing heap : "<<endl;
        //Printing Starts with index 1 as we are following 1 Based Indexing
        for(int i = 1; i <= size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    MaxHeap h(20);
    
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    h.printHeap();

    cout<<"deleting from heap : "<<endl;
    cout<<h.deleteFromHeap()<<endl;

    h.printHeap();
    


return 0;
}