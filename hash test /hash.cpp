#include <iostream>
#include <vector>


template <class dataTypeClass> class hashItem{
private:
dataTypeClass* mNextHashItem;
std::string mkey;
public:

hashItem();
hashItem(std::string akey):mNextHashItem(0){mkey = akey;}
hashItem(dataTypeClass &aHashItem);
~hashItem(){}

void setNextHashItem(const dataTypeClass* aHashItem){ mNextHashItem = aHashItem; }
void setNextHashItem(const dataTypeClass &aHashItem){ mNextHashItem = &aHashItem;}

};

template <class dataTypeClass> class hash{
private:
std::vector <dataTypeClass> hashVector;
std::string mName;
public:
hash(){}
hash(std::string aName = "unnamedHash"):mName(aName),hashVector(100,NULL){}
~hash(){std::cout<<"Hash "<<mName<<"destructing!";}
void addHashItem(dataTypeClass aHashItem, std::string akey){}
int hashFunction(dataTypeClass hashItem){return 0;}
void printVectorContents(){

for (typename std::vector<dataTypeClass>::iterator i = hashVector.begin(); i<hashVector.rend(); i++)
{
    std::cout<< *i << std::endl;
}

}

};
