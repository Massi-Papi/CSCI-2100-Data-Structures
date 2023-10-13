#include <iostream>
#include <random>
#include <chrono>
#include <string>
using namespace std;

int main() {
  
  default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> distribution(1,100);
  int number = distribution(generator);
  
  cout <<"I’ve picked a random number from 1 to 100, try to guess it." << endl;
  
  bool found = {false};
  int guesses = {0};
  while (!found){
    cout << "Guess a number: ";
    int userGuess = {1};
    cin >> userGuess;
    
    while(cin.fail()) {
    cout << "Error: Enter an integer number!"<< endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> userGuess;
    }

    if (userGuess > 100){
        cout << "Start with a number less than 100: " << endl;
    }

    if (userGuess < 100){
        cout << "Start with a positive number: " << endl;
    }
    //}
    if (userGuess == number){
      cout << "Correct" << endl;
      cout << "You guessed " << guesses << " times" << endl;
      found = true;
    }
    else if (userGuess > number) {
      cout << "Too high " << endl; 
    }

    else {
      cout << "Too low " << endl;
    }
    
    guesses++;
  }

  
}