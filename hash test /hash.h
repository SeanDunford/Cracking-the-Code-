#include <iostream>
#include <vector>


namespace myNamespace
{

class hashItem{
private:
hashItem* mNextHashItem;
std::string mKey;
public:

hashItem(std::string key)
hashItem(hashItem &aNextHashItem)
~hashItem()

void setNextHashItem(const hashItem* aHashItem)
void setNextHashItem(const hashItem &aHashItem)
};


class myHash{
private:
std::vector <int> hashVector;
std::string mName;
public:
myHash()
myHash(std::string aName)
~myHash()

void printHashName()
void addHashItem(hashItem ahashItem, int key)
int hashFunction(hashItem ahashItem)
void printVectorContents()
};
}
