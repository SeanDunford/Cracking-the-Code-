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
Cable = Unique(deadPool);   
if(Cable){
   cout<<"unique"; 
}
 else{cout<< "not unique";}
cin.get();
return 0; 
}
string sort(unsortedString)
{
  int length =  unsortedString.length;
  char temp1=unsortedString[0];
  char temp2=unsortedString[0];
  for (int i =0; i < length; i++)
    {
      for(int j =0; j<length; j++)
	{
	  temp2 = unsortedString[j];
	  
	}
      
      
    }
  return sortedString; 
}
bool Unique(string x)
{
  bool trueFalse[256] = {false}; 
  bool unique = true;
  int j = -1;
  int size; 



  size = x.size();
  for(int i = 0; i < size; i++)
    {
      j = x[i];
      cout << j << " & "<< x[i]<< " \n";
      if(trueFalse[j] == true)
	{
	  unique = false; 
	  break;
	}
      trueFalse[j]= true; 
    }
      return unique;
}
