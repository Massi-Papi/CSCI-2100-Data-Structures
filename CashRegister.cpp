#include <iostream>
using namespace std; 

class CashRegister{
    private:

    float finalSum;
    
    public:

    void purchase(float numberOfItems, float price){
        float items = numberOfItems * price;
        finalSum = finalSum + items;
    }

    float total(){
        cout << finalSum << endl; 
    }

    void clear(){
        finalSum = 0;
    }


};


int main(){
    CashRegister Test;
    Test.purchase(7,10.75);
    Test.purchase(3,54);
    Test.total();
    Test.clear();
    Test.total();
}