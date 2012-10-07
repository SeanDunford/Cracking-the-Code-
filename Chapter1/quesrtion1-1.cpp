#include <iostream>
#include <cstdlib>
using namespace std; 

bool Unique(string x);
int main()
{
string deadPool =""; 
bool Cable = false; 

cout<<"Please enter a string: "; 
cin>>deadPool;
cin.ignore();
cout << deadPool; 
Cable = Unique(deadPool);
cout << Cable; 
cin.get();
return 0; 
}

bool Unique(string x)
{
bool trueFalse = true; 
  return (trueFalse);
}

