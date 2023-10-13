#include <iostream> 
using namespace std;

int Copier(){
    double A;
    double B;
    double C;
    double D;
 
    cout << "Enter values with a space between each number for A, B, C, and D: " << endl;

    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;

    if(A <= C && B <= D){
        cout << "Output: 100% " << endl;
    }
    if(D >= A && C >= B){
        cout << "Output: 100% " << endl;
    }
    if((A- B) > 0 && (C-D) < 0){
        double oldC = C;
        C = D;
        D = oldC;
    }
    if((A - B) < 0 && (C-D) > 0){
        double oldA = A;
        A = B;
        B = oldA;
    }

    cout << ((A-C)/A) * 100 << " percent" << endl;

}

int main(){
Copier();

}