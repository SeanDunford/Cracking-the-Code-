#include <iostream>
#include <cstdlib>
using namespace std; 

int main()
{
  struct weird{
    int id; 
    int age;
    int salary; 
  };

  weird dude; 
  cout<<"Please enter your ID: ";
  cin>>dude.id; 
 cin.ignore();
   cout<<"Please enter your age: ";
   cin>>dude.age; 
 cin.ignore();
 cout<<"Please enter your salary: ";
 cin >>dude.salary;
 cin.ignore();
 cout << "Your Id is: "<<dude.id<<"\n";
 cout << "You are: "<<dude.age<<"\n";
 cout<<"You make: "<<dude.salary<<"\n";
 cin.get();
return 0; 
}


