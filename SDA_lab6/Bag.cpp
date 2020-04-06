#include "Bag.h"
#include "BagIterator.h"


Bag::Bag(){
	//ceva "new" pentru alocat??
	//this->next = new int{ 10 };
	//this->Tkey = new Node[10];
	this->m = 13333;
	this->Tkey = new Node[this->m];
	this->next = new int[this->m];
	int i, j;
	for (i = 0; i < this->m; i++) {
		this->Tkey[i].info = -999;
		this->next[i] = -1;
	}
	this -> firstEmpty = 0;
}


int Bag::toSet(){
	//keeps only one occurence of all elements from the bag
	//returns the number of removed elements
	int i, total = 0;

	//pass through all the elements from the bag
	//if the frequency is > 1, set it to 1 and add the difference 
	//to total

	for (i = 0; i < this->m; i++) {
		if (this->Tkey[i].info != -999) {
			if (this->Tkey[i].freq > 1) {
				total += this->Tkey[i].freq - 1;
				this->Tkey[i].freq = 1;
			}
		}
	}
	return total;
	//Complexity: Teta( m )
}

int Bag::hashCode(TElem e) const
{
	if (e < 0){
		return (-e);
	}
	return e;
	
}
int Bag::hash(TElem e) const
{
	return this->hashCode(e) % m;
}

void Bag::resize()
{
	int old_m = this->m;
	this->m *= 2;
	Node* new_elems = new Node[this->m];
	int *new_next = new int[this->m];

	this->firstEmpty = old_m;

	int i;
	for (i = 0; i < this->m; i++) {
		new_elems[i].info = -999;
//		new_elems[i].freq = 0;
		new_next[i] = -1;
	}
	//re-hash the existing elements
	int current, prev = -1;
	for (i = 0; i < old_m; i++) {
		int key = this->hash(this->Tkey[i].info);
		current = key;

		if (new_elems[key].info == -999) {
			//the position is empty
			new_elems[key].info = this->Tkey[i].info;
			new_elems[key].freq = this->Tkey[i].freq;
			this->firstEmpty = this->newEmpty();
		}
		//if the [key] position is occupied:
		// -- 1 -- search for the element on the list: if found, increase freq
		// -- 2 -- if it's not found, add it to the first empty position and link it to the key
		else {
			while (current != -1 && new_elems[current].info != this->Tkey[i].info) {
				prev = current;
				current = new_next[current];
			}
			if (current != -1) {
				//it means we've found the element, incerease the quantity
				new_elems[current].freq++;
			}
			else {
				new_elems[this->firstEmpty].info = this->Tkey[i].info;
				new_elems[this->firstEmpty].freq = 1;
				new_next[prev] = this->firstEmpty;
				//find the new FE position
				this->firstEmpty = this->newEmpty();
			}
		}
	}
	//delete[]this->Tkey;
	this->Tkey = new_elems;
	//delete[]this->next;
	this->next = new_next;
	//hai cu Doamne Ajuta!
}

void Bag::add(TElem e)
{
	if (this->firstEmpty == this->m)
		this->resize();

	int current, prev = -1;
	int key = this->hash(e);
	current = key;
	
	if (this->Tkey[key].info == -999) {
		//the position is empty
		this->Tkey[key].info = e;
		this->Tkey[key].freq= 1;
		this->firstEmpty = this->newEmpty();
		return;
	}
	//if the [key] position is occupied:
	// -- 1 -- search for the element on the list: if found, increase freq
	// -- 2 -- if it's not found, add it to the first empty position and link it to the key
	while (current != -1 && this->Tkey[current].info != e) {
		prev = current;
		current = this->next[current];
	}
	if (current != -1) {
		//it means we've found the element, incerease the quantity
		this->Tkey[current].freq++;
		return;
	}
	else {
		this->Tkey[this->firstEmpty].info = e;
		this->Tkey[this->firstEmpty].freq = 1;
		this->next[prev] = this->firstEmpty;
		//find the new FE position
		this->firstEmpty = this->newEmpty();
		return;
	}
}

bool Bag::remove(TElem e)
{
	//search-ul asta e absolut inutil..
	if(this->search(e) == false)
		return false;
	
	int prev = -1;
	int pos = this->hash(e);
	while (this->Tkey[pos].info != e) {
		prev = pos;
		pos = this->next[pos];
	}
	if (this->Tkey[pos].freq > 1) {
		this->Tkey[pos].freq--;
		return true;
	}
	int p, pp;
	bool over = false;
	while (!over) {
		p = this->next[pos];
		pp = pos;
		while (p != -1 && this->hash(this->Tkey[p].info) != pos)
		{
			pp = p;
			p = this->next[p];
		}
		if (p == -1)
			over = true;
		else
		{
			this->Tkey[pos] = this->Tkey[p];
			pos = p;
			prev = pp;
		} 
	}
	if (prev == -1) {
		this->Tkey[pos].info = -999;
		this->Tkey[pos].freq = 0;
		this->next[pos] = -1;
	}
	else {
		this->next[prev] = this->next[pos];
		this->Tkey[pos].info = -999;
		this->Tkey[pos].freq = 0;
		this->next[pos] = -1;
	}
	if (pos < this->firstEmpty)
		this->firstEmpty = pos;
	return true;
}

bool Bag::search(TElem e) const
{
	if (this->nrOccurrences(e) == 0) {
		return false;
	}
	return true;
}

int Bag::nrOccurrences(TElem e) const
{
	int current = 0;
	int pos = this->hash(e);
	if (this->Tkey[pos].info == -999)
		return 0;
	if (this->Tkey[pos].info == e) {
		//the element is in its Tkey position
		return  this->Tkey[pos].freq;
	}
	else {
		current = pos;
		while (current != -1) {
			current = this->next[current];
			if (this->Tkey[current].info == e) {
				return this->Tkey[current].freq;
			}
		}
	}
	return 0;
}

int Bag::size() const{
	int size = 0;
	int i = 0;
	for (i; i < this->m; i++) {
		if (this->Tkey[i].info != -999) {
			size += this->Tkey[i].freq;
		}
	}
	return size;
}

BagIterator Bag::iterator() const
{
	BagIterator it{ *this };
	return it;
}

bool Bag::isEmpty() const{
	return this->size() == 0;
}

int Bag::newEmpty() 
{
	int j;

	for (j = 0; j < this->m; j++) 
		if (this->Tkey[j].info == -999) {
			return j;
		}
	//when j gets to m
	return j;
}


void Bag::printBag()
{
	int i = 0;
	cout << "Info:\n";
	for (i = 0 ; i < this->m; i++) {
		if (this->Tkey[i].info != -999)
			cout << this->Tkey[i].info << "  ";
	}
	//cout << "\n";
	//cout << "Next:\n";
	//for (i = 0; i < this->m; i++) {
	//	cout << this->next[i]<<"  ";
	//}
	cout << "\n";
	cout << "Frequency:\n";
	for (i = 0; i < this->m; i++) {
		if (this->Tkey[i].freq > 0)
			cout << this->Tkey[i].freq << "  ";
	}
	cout << "\n";
}

Bag::~Bag()
{
}