#include <iostream>
#include <vector>
using namespace std;

template<class T>
class LinkedList
{
  private:
    //Stores the value and pointer to the next node in list 
    struct Node
    {
      T data;
      Node *next;
      Node(T val):data(val), next(nullptr) {}
    };

    //Storing Location of head and tail
    Node *head, *tail;

    // Size of list
    int _size;

    //Search Function
    Node *search(T val)
    {
      Node *currentNode = head;
      while(currentNode != nullptr)
      {
        if(currentNode->data == val)
        {
          return currentNode;
        }
        currentNode =currentNode->next;        
      }
      //Outputting an error
      cerr << "No such element in the list \n";
      return nullptr;
    }

    //Checking back of list for value 
    bool isIn(T val)
    {
      if(search(val) != nullptr)
      {
      return true;
      }
      return false;
    }

    //Append Function
    void append(T val)
    {
      Node *node = new Node(val);
      _size++;
      if (head == nullptr)
      {
        head = node;
        tail = node;
      }
      else
      {
        tail->next = node;
        tail = node;
      }
      
    }
    //Prepend Function
    void prepend(T val)
    {
      Node *node = new Node(val);
      _size++;
      if (head ==nullptr)
      {
        head = node;
        tail = node;
      }
      else
      {
        node->next = head;
        head = node;
      }
    }

  
    // Insert function
    void sortAndInsert(T newValue, T valueToBeAfter=NULL)
    { 
 
      if(head==nullptr || valueToBeAfter == NULL)
      {
        append(newValue);
        return;
      }

      //Find location of value after pointer
      Node *locationPtr = search(valueToBeAfter);      
      if(locationPtr != nullptr)
      {
        
        if(locationPtr == tail)
        {
          append(newValue);
        }
      
        else
        {
          Node *newNode = new Node(newValue);
          _size++;
          newNode->next = locationPtr->next;
          locationPtr->next = newNode;
        } 
      }
      else
      {
        //Outputting an error
        cerr << "The value given to be inserted after is not present.\n" << endl;
      }
    }

  public: 

    //Constructor
    LinkedList(): head(nullptr), tail(nullptr), _size(0) {}
    

    ~LinkedList()
    {
      Node *temporary = nullptr;
      while (head)
      {
        temporary = head;
        head = head->next;
        delete temporary;
      }
      head = nullptr;
    }

    // Size Function
    int size(){
      return _size;
    }


    // Print Function
    void printValues()
    {
      Node *node =head;
      while(node != nullptr)
      {
        cout << node->data <<endl;
        node = node->next;
      }
    }
    // Checking to see if it's on the list
    string within(T val)
    {
      if(isIn(val)==true)
      {
        return "True";
      }
      else
      {
        return "False";
      }
    }

    //Insert function
    void insert(T val)
    {
      Node* previous = nullptr;
      Node* temporary = head;

      
      if(temporary->data <= val)
      {
        prepend(val);
        return;
      }
      
      while(temporary != nullptr && temporary->data > val)
      {
        previous = temporary;
        temporary = temporary->next;
      }
      if(temporary==nullptr)
      {
        append(val);
        return;
      }
      else
      {
        sortAndInsert(val, previous->data);
      }
    }

    //Remove Function
    void removeValues(T val)
    {
      
      Node *temporary = head;
      Node *previous = nullptr;
      
      if(temporary!=nullptr && temporary->data == val)
      {
        head = temporary->next;
        delete temporary;
        _size--;
        return;
      }  
    
      while(temporary!=nullptr && temporary->data != val)
      {
        previous = temporary;
        temporary = temporary->next;
      }
      if(temporary == nullptr)
      {
        return;
      }
      previous->next = temporary->next;
      
      if(previous->next == nullptr)
      {
        tail = previous;
      }
      delete temporary;
      _size--;
    }


    //Test Function 1
    void testFill10()
    {
      for(int i=10;i>0;i--)
      {
        append(i); 
      }  

    }

    //Test Function 2
    void testFill69()
    {
      for(int i=69;i>0;i--)
      {
        append(i); 
      }  

    }

    //Test Function 3
    void testFill50()
    {
      for(int i=50;i>0;i--)
      {
        append(i); 
      }  

    }
    
};


int main() {

  cout << endl<<endl;
  LinkedList<int> listSoBig;
  listSoBig.testFill10();
  cout << listSoBig.size()<< endl;
  cout << listSoBig.within(30)<< endl;
  listSoBig.insert(69);
  listSoBig.insert(34);
  listSoBig.printValues();
  cout << ' ' << "\n";
  listSoBig.removeValues(69);
  listSoBig.printValues();
  cout << listSoBig.size() <<endl;

  LinkedList<int> listSoBig2;
  listSoBig2.testFill69();
  cout << listSoBig2.size()<< endl;
  cout << listSoBig2.within(100)<< endl;
  listSoBig2.insert(78);
  listSoBig2.insert(76);
  listSoBig2.printValues();
  cout << ' ' << "\n";
  listSoBig2.removeValues(69);
  listSoBig2.printValues();
  cout << listSoBig2.size() << endl;

  LinkedList<int> listSoBig3;
  listSoBig3.testFill50();
  cout << listSoBig3.size()<< endl << endl;
  cout << listSoBig3.within(50)<< endl;
  listSoBig3.insert(60);
  listSoBig3.insert(250);
  listSoBig3.printValues();
  listSoBig3.removeValues(100);
  listSoBig3.printValues();
  cout << listSoBig3.size() <<endl;

  return 0;
  
}
