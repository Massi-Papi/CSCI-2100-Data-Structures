#include <iostream>
using namespace std;

int Conversion(){
    int inches;
    int feet;
    int newInches; 

    cout << "How many inches do you want to convert to feet?" << endl;
    cin >> inches;

    feet = inches / 12;
    newInches = inches % 12;

    cout << feet <<  " feet and " << newInches << " inches." << endl;
    
    return 0;
}
int main(){
    Conversion();
}
