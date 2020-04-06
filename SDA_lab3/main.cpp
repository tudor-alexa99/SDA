#pragma once
#include <iostream>

#include "MyTest.h"
#include "ShortTest.h"
#include "SortedBag.h"
#include "ExtendedTest.h"
#include "SortedBagIterator.h"
using namespace std;

void testDV() {
	DynamicVector<int>elems;
	elems.add(1);
	//elems.add(2);
	elems.add(3);
	elems.add(4);
	elems.insert(2, 1);
	for (int i = 0; i < elems.getSize(); i++)
		cout << elems[i] << " ";

}

int main() {
	//myTest();
	testAll();
	//testAllExtended();
	//testDV();
	//testIterator();
	cout << endl;
	system("pause");
	return 0;
}

