#include <iostream>
#include <string> 
using namespace std;
#include <stdio.h>

void word(){

    string word = ""; 
    string newWord = "";
    int Counter = 0;

    cout << "Enter a word: ";
    cin >> word;

    for(int i = 0; i < word.length(); i++){
    
        newWord += word[i];  
        newWord += word[i];
 
    }

    cout << newWord << endl;
}


int main(){
word();
return 0;
}