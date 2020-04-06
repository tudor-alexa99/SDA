#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r)
{
	DynamicVector<TComp> _set;
	this->set = _set;
	this->relation = r;
}

bool SortedSet::add(const TComp& e)
{
	//check if the element is already in the list
	//if not, add it to the correct position and return true
	//if it is, return false
	if (this->search(e) == true)
		return false;

	//find the position to insert a given element
	//for (int i = 0; i< this->set.getSize(); i++)
	int i = 0;
	while (i < this->set.getSize() && !this->relation(this->set[i] , e))
	{
		i++;
	}

	this->set.insert(e, i);
	return true;
}

bool SortedSet::remove(TComp e)
{
	if (this->search(e))
		for (int i = 0; i <= this->set.getSize(); i++)
		{
			TComp eq = this->set[i];
			if (eq == e)
			{
				this->set.remove(i);
				return true;
			}
		}
	return false;
}

bool SortedSet::search(const TComp & elem)
{
	{
		for (int i = 0; i <= this->set.getSize(); i++)
		{
			TComp current = this->set[i];
			if (current == elem)
				return true;
		}
		return false;
	}
}
int SortedSet::size() const
{
	return this->set.getSize();
}
bool SortedSet::isEmpty() const
{
	if (this->set.getSize() == 0)
		return true;
	return false;
}
SortedSetIterator SortedSet::iterator() const
{
	return SortedSetIterator(*this);
	//return ssi;
}

TComp SortedSet::operator[](int i) const
{

	return this->set.getElem(i);
}

//int SortedSet::find(const TComp & e)
//{
//	for (int i = 0; i <= this->set.getSize(); i++)
//	{
//		TComp current = this->set[i];
//		if (current == e)
//			return i;
//	}
//	return -1;
//}


SortedSet::~SortedSet()
{
}
