#include <iostream>

#include "MyTest.h"
#include "SortedBag.h"
#include "SortedBagIterator.h"

using namespace std;
bool relationx(TComp r1, TComp r2) {
	return r1 <= r2;
}
void myTest()
{
	SortedBag sb(relationx);
	sb.add(1);
	sb.add(1);
	sb.add(2);
	sb.add(3);
	sb.add(3);
	sb.add(4);
	sb.add(4);
	

	SortedBagIterator it = sb.iterator();
	it.first();
	it.next();
	it.next();
	it.next();
	it.next();
	//it.next();
	cout << it.getCurrent()<<endl;
	cout <<"NR of elems with max frequency "<< sb.elementsWithMaximumFrequency()<<endl;
}
