#include "BagIterator.h"

BagIterator::BagIterator(const Bag & c) :elems{ c }
{
	int i = 0;
	if (this->elems.size() == 0) {
		this->current = -1;
	}
	else {
		while (i < this->elems.m && this->elems.Tkey[i].info == -999) {
			i++;
		}
	this->current = i;
	this->fq = 1;
	}
}
void BagIterator::first(){
	this->current = 0;
	this->fq = 0;
}

void BagIterator::next(){
	if (!this->valid()) {
		throw std::exception();
	}
	if (this->fq <= this->elems.Tkey[this->current].freq) {
		//current stays the same
		this->fq++;
	}
	else {
		int i = this->current + 1;
		while (this->elems.Tkey[i].info == -999 && i < this->elems.m) {
			i++;
		}
		if (i == this->elems.m) {
			this->current = -1;
		}
		else{
			this->current = i;
			this->fq = 1;
		}
	}
	if (this->fq > this->elems.Tkey[this->current].freq) {
		for (int j = this->current; j < this->elems.m; j++) {
			if (this->elems.Tkey[j].info = -999)
				return;
		}
		this->current = -1;
	}
}

bool BagIterator::valid() const{
	return this->current != -1;
}

TElem BagIterator::getCurrent() const
{
	if (!this->valid()) {
		throw std::exception();
	}
	return this->elems.Tkey[this->current].info;
}
