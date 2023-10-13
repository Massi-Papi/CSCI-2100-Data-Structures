#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ItemType template so any type of data is accepted
template <typename ItemType>

class Deque{

private:
    vector<ItemType> deque ;
    int front = -1;   // adding first element makes front and back at 0
    int back = 0;
    int max = 4;
    int size = 0;
   
  public:

    // Inserts element from beginning by measuring the size then the front of the deque

    void pushFront(ItemType item){
      if (size == max){
        resize();
      }
      if (front == -1){
        front = 0;
        deque.push_back(item);
      }

      else{
        front--;
        if (front < 0){
          front = front + max;
        }
        deque[front] = item;
      }
      size++;
    }

    // inserts element from the end by measuring the size, the front, and the back of the deque
    void pushBack(ItemType item){
      if (size == max){
        resize();
        cout << "Deque is full" << endl;
      }
      if (front == -1){
        front = 0;
        deque.push_back(item);
      }
      else {
        back ++;
        if (back == max - 1){
          back = 0;
        }
        deque[back] = item;
      }
      size++;
    }

    // needs resize() method in order to control max and size
    void resize(){
      int counter = {0};
      vector<ItemType> resizedDeque;
      
      // creates a new vector with zeros that is doubled the size
      for (int i = {0}; i < (max * 2); i++){
        resizedDeque.push_back(0);
      }
      for (int i = {0}; i < front; i++){
       
        // moves element starting from front to end of deque
        if (front+i < max){
          resizedDeque[i] = deque[front];
        }
        
        // move element starting from begining of deque to rear
        else{
          resizedDeque[i] = deque[counter];
          counter++;
        }
      resizedDeque[max-1] = deque[back];
      }
    deque = resizedDeque;
    
    //resets front, back, max after moving elements
    front = 0;
    back = max - 1;
    max *= 2;
    }
    // Removes Item from front
    ItemType popFront(){
      if (size == 0){
        cout << "Cannot popFront() from empty deque" << endl;
        return -1;
      }

      // intermediate variable to keep track of front
      int removeFront = deque[front];
      if (front < max-1)
        front++;
      else front = 0;
      size--;
      return removeFront;
    }
   
    // intermediate variable to keep track of back
    ItemType popBack(){
      if (size == 0){
        cout << "Cannot popBack() from empty deque" << endl;
        return -1;
      }
      int removeBack = deque[back];
      if (back > 0)
        back--;
      else
        back = max - 1;
      size--;
      return removeBack;
    }
   
    // returns front element
    ItemType peekFront() {
      if (size == 0){
      }
      return deque[front];
    }
   
    // returns back element
    ItemType peekBack(){
      if (size == 0){
      }
      return deque[back];
    }
    // Checks if deque is empty
    void isEmpty(){
      if (size == 0){
        cout << "Deque is empty" << endl;
      }
    }
    // Returns size of deque
    int getLength(){
      return deque.size();
    }

    // Prints deque in order starting from front
    void print(){
      if (size == 0){
        cout << "Deque is empty" << endl;
      }
      else{
        int resetFront = front;
        for(int i = 0; i<size;i++){
          cout << deque[front] << " ";
          if (front == max-1){
            front = 0;
            }
          else{
            front++;
            }      
        }
      cout << endl;
      front = resetFront;
      }
  }
};

int main(){

  // extensive testing with integers that shows what is at the front and end of the deque
  Deque<int> test;
  test.popFront();    // testing popFront() on a empty deque
  test.popBack();     // testing popBack() on a empty deque
  test.pushFront(5);
  test.pushBack(9);
  test.pushBack(1);
  test.pushFront(3);
  test.print();
  test.pushFront(8);  // forcing to resize deque
  test.pushBack(16);
  test.pushBack(2);
  test.pushBack(3);
  cout << "After adding 4 more elements to deque, we get: " << endl;
  test.print();

  cout << "The front of the deque is: " << test.peekFront() << endl;
  cout << "The back of the deque is: " << test.peekBack() << endl;
  test.print();
  test.popBack();     // deleting from back
  test.print();
  test.popFront();    // deleting from front
  test.print();
  test.popBack();
  test.print();
  test.popBack();
  test.print();
  test.isEmpty();


// testing with simple strings
  Deque<string> testString;
  cout << "Strings are also applicable." << endl;
  testString.pushFront("A");
  testString.pushFront("B");
  
  testString.print();
  cout << "The front of the deque is: " << testString.peekFront() << endl;
  cout << "The back of the deque is: " << testString.peekBack() << endl;

  // This tests multiple strings in a set
  Deque<string> secondTest;
  cout << "Second Test" << endl;
  secondTest.pushFront("how are you?");
  secondTest.pushFront("Hello,");
  
  secondTest.print();
  cout << "The front of the deque is: " << secondTest.peekFront() << endl;
  cout << "The back of the deque is: " << secondTest.peekBack() << endl;
};