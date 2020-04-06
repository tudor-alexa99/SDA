#pragma once
#include "Bag.h"
#include <exception>

using namespace std;
//unidirectional iterator for a container
class Bag;

class BagIterator {
	friend class Bag;
private:
	//after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty
	const Bag& elems;
	BagIterator(const Bag& c);
	int current;
	int fq;
public:
	//sets the iterator to the first element of the container
	void first();

	//moves the iterator to the next element
	//throws exception if the iterator is not valid
	void next();

	//checks if the iterator is valid
	bool valid() const;

	//returns the value of the current element from the iterator
	// throws exception if the iterator is not valid
	TElem getCurrent() const;
};


