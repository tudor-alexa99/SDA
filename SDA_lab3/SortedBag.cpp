
#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r)
{
	this->head = nullptr;
	this->tail = nullptr;
	this->relation = r;
}

int SortedBag::elementsWithMaximumFrequency() const
{
	//returns the number of elems with max frequency
	//if the SortedBag is empty, returns 0
	if (this->isEmpty())
		return 0;

	auto *current = this->head;
	//maxf = maximum frquency , nrfreq = the number of elems with the given frequency
	//currentf = the frequency of the current element
	int maxf, nrfreq = 1, currentf;
	maxf = current->freq;
	while(current != nullptr){
		currentf = current->freq;
		//if a higher frequency is found
		if (currentf > maxf)
		{
			//reset the number of elements with the max frequency
			maxf = currentf;
			nrfreq = 1;
		}
		//if another number with the same frequency is found
		else if (currentf == maxf)
			//increase the number of elems with the same frequency
			nrfreq++;
		current = current->next;
	}
	return nrfreq;
}

//functie iterator

void SortedBag::add(TComp e)
{
	//if it exists, increase the frequence, else, add a pair <Tcomp e, int 1> 
	//int i;
	////use the search( e ) function
	//if (this->search(e) == true) {
	//	for (i = 0; i < this->elems.getSize(); i++)
	//		if (this->elems.getElem(i).first == e)
	//			this->elems[i].second++;
	//	return;
	//}

	//int pos =-1;
	//for(i = 0 ; i < this->elems.getSize(); i++)
	//	if (this->relation(this->elems.getElem(i).first, e) == false)
	//	{
	//		pos = i;
	//		break;
	//	}
	////if the given element should be inserted tot the last position, use add
	//if (pos == -1) {
	//	auto pair = make_pair(e, 1);
	//	this->elems.add(pair);
	//}
	//else {
	//	//if it should be inserted in the pos position
	//	auto pair = make_pair(e, 1);
	//	this->elems.insert(pair, pos);
	//	// auto aux = this->elems.getElem(pos);
	//}

	if (this->search(e))
	{
		auto *current = this->head;
		while (current != nullptr)
		{
			if (current->val == e)
			{
				current->freq++;
				return;
			}
			current = current->next;
		}
	}
	//if it was not found

	auto *current = this->head;
	//look for the position of the element 
	while (current != nullptr && this->relation(current->val, e) == false)
	{
		current = current->next;
	}
	node *n = new node;


	if (this->head == nullptr)
	{
		this->head = n;
		this->tail = n;
		n->freq = 1;
		n->next = nullptr;
		n->prev = nullptr;
		n->val = e;
		return;
	}
	
	n->val = e;
	n->freq = 1;
	if (this->relation(e, this->head->val))
	{
		n->prev = nullptr;
		n->next = current;
		this->head = n;
	}
	else if (this->relation(this->tail->val, e)) {
		n->next = nullptr;
		n->prev = this->tail;
		this->tail = n;
	}
	else 
	{
		n->next = current;
		current->prev = n;
		//n->prev->next = n;
	}
}

bool SortedBag::remove(TComp e)
{
	if (this->search(e) == false)
		return false;

	auto *current = this->head;
	while (current != nullptr)
	{
		if (current->val == e)
		{
			current->prev->next = current->next;
			current->next->prev = current->prev;
			return true;
		}
		else
			current = current->next;
	}
	return false;
	//if the frequency is 1, remove the element, else, decrement the frequency
	//int i;
	//if (this->search(e) == false)
	//	return false;
	//for (i = 0; i <this->elems.getSize(); i++)
	//	if (e == this->elems[i].first) {
	//		//i will be the position of the element
	//		break;
	//	}
	//auto current = this->elems.getElem(i);

	//if (current.second == 1) {
	//	this->elems.remove(i);
	//}
	//else
	//	this->elems[i].second--;
	//return true;
}

bool SortedBag::search(TComp e) const
{
	//for (int i = 0; i < this->elems.getSize(); i++)
	//{
	//	auto current = this->elems.getElem(i);
	//	if (current.first == e)
	//		return true;
	//}
	//return false;

	auto *current = this->head;
	while (current != nullptr) {
		if (current->val == e)
			return true;
		current = current->next;
	}
	return false;
}

int SortedBag::nrOccurrences(TComp e) const
{
	auto *current = this->head;
	while (current != nullptr) {
		if (current->val == e)
			return current->freq;
		current = current->next;
	}
	return 0;
}

int SortedBag::size() const
{
	//each element has a frequency
	//parse through them and add the frequencies
	int total = 0;
	//for (int i = 0; i < this->elems.getSize(); i++)
	//	total += this->elems.getElem(i).second;
	auto *current = this->head;
	while (current != nullptr)
	{
		total+= current->freq;
		current = current->next;
	}
	return total;
}

SortedBagIterator SortedBag::iterator() const
{
	return SortedBagIterator(*this);
}

SortedBag::~SortedBag()
{
}
