#pragma once

#include "SortedSet.h"

//class SortedSet;

//unidirectional iterator for a container

class SortedSetIterator {

	friend class SortedSet;
private:

	//contains a reference of the container it iterates over
	SortedSetIterator(const SortedSet& toIterate);

	const SortedSet& toIterate;

	/* representation specific for the iterator*/
	int current = 0;

public:

	//Constructor receives a reference of the container.
	//after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty
	//sets the iterator to the first element of the container
	void first();

	//moves the iterator to the next element
	//throws exception if the iterator is not valid
	void next();

	int getCurrent() const;

	//checks if the iterator is valid
	bool valid() const;

	//returns the value of the current element from the iterator
	// throws exception if the iterator is not valid
	//TElem getCurrent() const;


	~SortedSetIterator();

};


