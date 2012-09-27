#include <iostream>
#include <vector>
#include "hash.h"

using myNamespace::hashItem;
using myNamespace::myHash;
hashItem::hashItem(std::string akey):mNextHashItem(0){mKey = akey;}
hashItem::hashItem(hashItem &aNextHashItem);

hashItem::~hashItem();
void hashItem::setNextHashItem(const hashItem* aHashItem);
void hashItem::setNextHashItem(const hashItem &aHashItem);



myNamespace::myHash::myHash(std::string aName = "unnamedHash"):mName(aName),hashVector(100){}
myNamespace::myHash::~myHash(){std::cout<<"Hash "<<mName<<"destructing!";}
void myNamespace::myHash::addHashItem(dataTypeClass aHashItem, std::string akey){}
int myNamespace::myHash::hashFunction(dataTypeClass hashItem){return 0;}
void myNamespace::myHash::printHashName(){ cout << endl << "Hi I am a hash, my name is: "<<myNamespace::myHash::mName;}
void myNamespace::myHash::printVectorContents(){

for (typename std::vector<dataTypeClass>::iterator i = hashVector.begin(); i != hashVector.end(); i++)
{
    std::cout<< *i << std::endl;
}

}

};
