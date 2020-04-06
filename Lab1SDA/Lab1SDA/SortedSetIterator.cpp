#include "SortedSetIterator.h"

#include <exception>


SortedSetIterator::SortedSetIterator(const SortedSet& toIterate) : toIterate(toIterate) {

	this->current = 0;
	//this->toIterate = toIterate;
}

void SortedSetIterator::first()
{
	this->current = 0;
}

void SortedSetIterator::next()
{
	if (this->valid())
		this->current++;
	//else 
	//	throw std::exception("Invalid");
}

int SortedSetIterator::getCurrent() const
{
	return this->toIterate.set.getElem(this->current);
}

bool SortedSetIterator::valid() const
{
	return this->getCurrent() < this->toIterate.size() && this->toIterate.size() != 0;
}


SortedSetIterator::~SortedSetIterator()
{

}
