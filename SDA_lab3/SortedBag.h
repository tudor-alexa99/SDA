#pragma once
#include <utility>

//#include "SortedBagIterator.h"
#include "DynamicVector.h"
using namespace std;

typedef int TComp;

typedef TComp TElem;

class SortedBagIterator;

typedef bool(*Relation)(TComp, TComp);

struct node
{
	TComp val;
	int freq;
	node *prev, *next;
};

class SortedBag {

friend class SortedBagIterator;

private:

	//A DV of pairs, -> the std::pair also has a template : the element itself (TComp) and its frequency (int)
	//DynamicVector< std::pair <TComp, int> > elems;
	node* head;
	node* tail;
	Relation relation;
	/*representation of SortedBag*/



public:

	//constructor

	SortedBag(Relation r);
	// teta(n)
	int elementsWithMaximumFrequency () const;

	//adds an element to the sorted bag


	void add(TComp e);



	//removes one occurrence of an element from a sorted bag

	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)

	bool remove(TComp e);



	//checks if an element appearch is the sorted bag

	bool search(TComp e) const;



	//returns the number of occurrences for an element in the sorted bag

	int nrOccurrences(TComp e) const;



	//returns the number of elements from the sorted bag

	int size() const;



	//returns an iterator for this sorted bag

	SortedBagIterator iterator() const;



	//checks if the sorted bag is empty

	bool isEmpty() const { return this->size() == 0; }



	//destructor

	~SortedBag();

};