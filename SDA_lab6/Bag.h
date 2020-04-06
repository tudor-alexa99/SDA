#pragma once
#include <iostream>
#include <vector>
typedef int TElem;

using namespace std;

class BagIterator;

typedef struct Node {
	//??ceva relatie hash sa mor io de stiu ceva
	int freq;
	TElem info;
};


class Bag {
	friend class BagIterator;
private:
	//std::vector<Node> Tkey;
	//std::vector<int> next;
	Node* Tkey;
	int *next;
	int m;
	int firstEmpty;

	//std::vector<HashTable> elems;

	/*representation of Bag*/

public:
	//constructor

	Bag();
	int	hash(TElem e) const;
	
	//Bag();
	
	int toSet();

	int hashCode(TElem e) const;
	//?? ãllalt constructor
	//Bag(ceva hash);

	//adds an element to the bag

	//
	void resize();

	void add(TElem e);

	//removes one occurrence of an element from a bag

	//returns true if an element was removed, false otherwise (if e was not part of the bag)

	bool remove(TElem e);

	//checks if an element appearch is the bag

	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag

	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is 
	bool isEmpty() const;

	int newEmpty();

	//asta-i de la mine

	void printBag();

	//destructor
	~Bag();
};