#include <iostream>
#include <cstdlib>
using namespace std; 
int multiplication(int x, int y);
int main()
{
int wholeNumber =0; 
char letter = 'a'; 
float decimal = 4.2; 
int a,b,c,d;
int product; 


 int random1 = rand() ;
 int random2 = rand();

a=b=c=d=42; 
 product = multiplication(random1, random2);
 cout <<"Your random number is: "<< product<<"/n"; 
cout <<"Hey you I'm alive!\n This is an int: "<<wholeNumber<<"\n This is a letter: "<<letter<<"\n This is a decimal: "<<decimal<<"\nFirst: "<<a<<" Second: "<<b<<" Third: "<<c<<" Fourth: "<<d<<"\n";
 cout <<"Please, enter a #: "; 
cin>>wholeNumber;
 cout<<"You entered: "<<wholeNumber<< "\n"; 
cin.ignore();
 if (wholeNumber > 100)
   {
     cout << "wow big spender \n";
}
return 0; 
}

int multiplication(int x, int y)
{
int product; 
 product = x*y; 
  return (product);
}

