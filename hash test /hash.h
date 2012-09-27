#include <iostream>
#include <vector>


template <class dataTypeClass> class hashItem{
private:
dataTypeClass* mNextHashItem;
std::string key;
public:

hashItem(std::string key);
hashItem(dataTypeClass &aNextHashItem);
~hashItem();

void setNextHashItem(const dataTypeClass* aHashItem);
void setNextHashItem(const dataTypeClass &aHashItem);
template <dataTypeClass> void printVectorContents();
};


template <class dataTypeClass> class hash{
private:
std::vector <dataTypeClass> hashVector;
std::string mName;
public:
hash();
hash(std::string aName);
~hash();

void addHashItem(dataTypeClass hashItem, int key);
int hashFunction(dataTypeClass hashItem);
};
