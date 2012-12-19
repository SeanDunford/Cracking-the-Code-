#include "stdafx.h"
#include <iostream>
#include <vector>

namespace myNameSpace
{
	class myHash{
	private:
		std::vector<std::string> myVector;
		std::string mHashName; 
		void initVec(); 
	public:
		myHash();
		myHash(std::string);
		~myHash(); 
		void printVector(); 


	};

	class hashItem{
	private:
		hashItem* mNextHashItem; 
		std::string mKey;
		std::string mPassword; 
	public:
		hashItem(hashItem*, std::string); 
		~hashItem(); 	
	};

}