#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SortedList {
private:
    Node* head;

public:
    SortedList() {
        head = nullptr;
    }

    void add(int data) {
        Node* newNode = new Node(data);

        // If the list is empty, add the new node as the head of the list
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // If the new node should be added at the beginning of the list,
        // set it as the new head of the list
        if (data < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Otherwise, find the correct position for the new node and
        // insert it there
        Node* prev = head;
        Node* curr = head->next;
        while (curr != nullptr && curr->data < data) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
    }

    void remove(int data) {
        // If the list is empty, there is nothing to remove
        if (head == nullptr) {
            return;
        }

        // If the node to be removed is the head of the list,
        // set the next node as the new head
        if (head->data == data) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        // Otherwise, search for the node to be removed and remove it
        Node* prev = head;
        Node* curr = head->next;
        while (curr != nullptr && curr->data != data) {
            prev = curr;
            curr = curr->next;
        }

        // If the node was found, remove it
        if (curr != nullptr) {
            prev->next = curr->next;
            delete curr;
        }
    }

    //Checks to see if integer is in list
    bool contains(int data) {
        Node* curr = head;
        while (curr != nullptr && curr->data != data) {
            curr = curr->next;
        }
        return curr != nullptr;
        
    }

    // Prints out sorted list

    void printList() {
        Node* curr = this->head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    SortedList list;

    // Add some elements to the list
    list.add(5);
    list.add(1);
    list.add(3);
    list.add(2);
    list.add(69);
    list.add(1000);
    list.add(-8);
    list.add(0);
    list.printList();
    list.remove(3);
    list.printList();
    list.remove(2);
    list.printList();
    return 0;
}