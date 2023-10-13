//Using the class definition above as a model, we are going to try to write a C++ class that stores a date. 
// In addition to storing the date, it should have the ability to format the date and return a string of the form “February 14, 2005”.



#include <iostream> 
#include <string>
using namespace std;

class myDate {

    private:
    string _Month;
    int _Day;
    int _Year;


    public:
    int getDay(){
        return _Day;
    }

    int getYear() const{
        return _Year;
    }

    int setDay(int newDay){
        _Day = newDay;
        return 0;
    }

    void setMonth(string newMonth){
        _Month = newMonth;
    }

    void setYear(int newYear){
        _Year = newYear;
    }

};

int main(){
    myDate testRun;
    cout << testRun.setDay(10) << endl;
    
}