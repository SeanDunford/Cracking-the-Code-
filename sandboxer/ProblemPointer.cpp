#include <iostream>
#include <cstdlib>
using namespace std; 

int main()
{
  int *a; 
  int *b; 
  int x = 7; 

a = &x; 
 cout<<"Please enter a number: ";
cin>>x; 
cin.ignore(); 
cout <<*a<<"\n";
cin.get(); 

return 0; 
}


