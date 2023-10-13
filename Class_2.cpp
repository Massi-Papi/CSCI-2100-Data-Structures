#include <iostream>
using namespace std;

class Statistics
{
private:

int min_, max_;

public:

    void Add(int num)
    {
      if (num < min_){
        min_ = num;
      }

      if (num > max_){
        max_ = num;
      }
    }

    int GetMin() const
    {
      cout << min_ << endl;

      return 0;
    }

    
    int GetMax() const
    {
      cout << max_ << endl;

      return 0;
    }
};


int main(){
    
Statistics stats;
stats.Add(58483);
stats.Add(10);
stats.Add(40000);
stats.Add(39);
stats.GetMax();
stats.GetMin();
}