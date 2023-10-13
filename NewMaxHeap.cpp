#include <iostream>
#include <vector> 
using namespace std;

template <typename T> class MaxHeap{
    private:
        int vectorSize;
        vector<T> maxHeapVector;
        int parentIndex(int i) { return i >> 1;};
        int leftChildIndex(int i) { return i << 1;}; 
        int rightChildIndex(int i) { return (i << 1) + 1;};

    public:
        // Constructor for MaxHeap
        MaxHeap(vector<T> vect) {
            maxHeapVector = vect;
        }

        // Function to insert an item in the max heap
        void insertItem(int val) {
            if (vectorSize + 1 >= maxHeapVector.size()){
                maxHeapVector.push_back(0);
            }
            maxHeapVector[++ vectorSize] = val;
            maxHeapPercolateUp(vectorSize);
            return;
        }

        // Function to delete the root item
        void deleteRoot() {
            T maxItem = maxHeapVector[1];
            swap(maxHeapVector[1], maxHeapVector[vectorSize--]);
            maxHeapPercolateDown(1);
        }
        
        // Function for percolate up
        void maxHeapPercolateUp(int i) {
            if (i > vectorSize) return;
            if (i == 1) return;
            if (maxHeapVector[i] > maxHeapVector[parentIndex(i)]) {
                swap(maxHeapVector[parentIndex(i)], maxHeapVector[i]);
            }
            maxHeapPercolateUp(parentIndex(i));
        }

        // Function for percolate down
        void maxHeapPercolateDown(int i) {
            if (i > vectorSize) return;
            int swapId = i;
            if (leftChildIndex(i) <= vectorSize && maxHeapVector[i] < maxHeapVector [leftChildIndex(i)]) {
                swapId = leftChildIndex(i); 
            }
            if (rightChildIndex(i) <= vectorSize && maxHeapVector[swapId] < maxHeapVector [rightChildIndex(i)]) {
                swapId = rightChildIndex(i);
            }
            if (swapId != i){
                swap(maxHeapVector[i], maxHeapVector[swapId]);
                maxHeapPercolateDown(swapId);
            }
            return;
        }

        // Function that returns max heap
        vector<T> getMaxHeap() {
            return maxHeapVector;
        }

        // Function that return the size of the max heap
        int getSize() {
            return vectorSize;
        }
};

int main() {
    vector<int> maxHeapVect = {-1};
    MaxHeap<int> maxHeap(maxHeapVect);
    maxHeap.insertItem(10);
    maxHeap.insertItem(120);
    maxHeap.insertItem(34);
    maxHeap.insertItem(41);
    maxHeap.insertItem(5);

    maxHeapVect = maxHeap.getMaxHeap();

    MaxHeap<char> maxHeapWithChar({});
    maxHeapWithChar.insertItem('a');
    maxHeapWithChar.insertItem('c');
    maxHeapWithChar.insertItem('b');
    maxHeapWithChar.insertItem('d');
    maxHeapWithChar.insertItem('e');

    // cout << "The vector elements in the max heap are : ";
    // for(int i=0; i < maxHeap.getSize(); i++)
    // cout << maxHeapVect.at(i) << ' ';

    return 0;
}
