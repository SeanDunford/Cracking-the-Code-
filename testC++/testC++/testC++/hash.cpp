#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "hash.h"

using myNameSpace::myHash; 
using myNameSpace::hashItem; 

myHash::myHash(){ 
			myHash::initVec();
	 }
myHash::myHash(std::string aHashName = "unnamedHash"):mHashName(aHashName){
			myHash::initVec();
		}
void myHash::initVec(){
		for (int i = 0; i<100; i++)
		{
			myVector.push_back("hello"); 
		}


}
myHash::~myHash(){
	std::cout <<std::endl<< "Destructing " << mHashName<< std::endl;  }

void myHash::printVector(){
	int j = 0; 
	for(auto i = myVector.begin(); i != myVector.end(); i++)
	{
		std::cout <<std::endl<<"Vector["<<j<<"] is equal to: "<< *i<<std::endl;
		j++; 
	}
}


hashItem::hashItem(hashItem* aHashItem, std::string aKey):mNextHashItem(aHashItem), mKey(aKey){}
hashItem::~hashItem(){ std::cout << "destructing hashITem: "<<mKey; }
