#pragma once
#include "DynamicVector.h"
//#include"SortedSetIterator.h"

typedef int TElem;
typedef TElem TComp;

class SortedSetIterator;

typedef bool(*Relation)(TComp, TComp); 


class SortedSet {
	friend class SortedSetIterator;
private:
	
	DynamicVector<TComp> set;
	Relation relation;
	/*Representation of the SortedSet*/


public:

	//constructor

	SortedSet(Relation r);



	//adds an element to the sorted set

	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 

	//it returns false

	bool add(const TComp& e);


	//returns the position of e if it belongs to the set, -1 otherwise
	//int find(const TComp & e);


	//removes an element from the sorted set

	//if the element was removed, it returns true, otherwise false

	bool remove(TComp e);



	//checks if an element is in the sorted set

	bool search(const TComp& elem);





	//returns the number of elements from the sorted set

	int size() const;



	//checks if the sorted set is empty

	bool isEmpty() const;



	//returns an iterator for the sorted set

	SortedSetIterator iterator() const;

	TComp operator[](int i) const;


	// destructor

	~SortedSet();





};
