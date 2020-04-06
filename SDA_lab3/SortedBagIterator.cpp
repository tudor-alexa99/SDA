#include "SortedBagIterator.h"
//#include "SortedBag.h"



SortedBagIterator::SortedBagIterator(const SortedBag& bag) :bag(bag){
	this->current = bag.head;
	this->freq = 0;
}

SortedBagIterator::~SortedBagIterator()
{
}

TElem SortedBagIterator::getCurrent() const
{
	if (!this->valid())
		throw std::exception();
	return current->val;
}

void SortedBagIterator::first()
{
	this->current = this->bag.head;
	this->freq = 0;
}

void SortedBagIterator::next()
{
	if (!this->valid())
		throw std::exception();
	this->freq++;
	if (this->freq >= this->current->freq) {
		this->current = this->current->next;
		this->freq = 0;
	}
}

bool SortedBagIterator::valid() const
{
	return this->current != nullptr;
}
