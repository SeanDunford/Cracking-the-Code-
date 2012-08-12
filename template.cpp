#include <iostream>
#include <cstdlib>
using namespace std; 

int foo(int x);
int main()
{
int wholeNumber =0; 


cout<<"Please enter a number: "; 
cin>>wholeNumber;
product = multiplication(wholeNumber);
 cout <<"Your random number is: "<< wholeNumber<<"/n"; 
cin.ignore();
 if (wholeNumber > 100)
   {
     cout << "wow big spender \n";
}
cin.get();
return 0; 
}

int multiplication(int x)
{
int product = rand(); 
 product = x*product; 
  return (product);
}

