#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


void bagTest() {
	Bag bag{};
	for (int i = 1; i< 12; i++) {
		bag.add(i);
		bag.add(i);
		bag.add(i);
	}
	bag.printBag();
	cout << endl;
	cout<<"Nr of removed elements: "<< bag.toSet()<<"\n";
	cout << "New bag:\n";
	bag.printBag();

}

int main() {
	/*Bag bag{};
	for (int i = 0; i < 10; i++) {
		bag.add(i);
	}
	bag.add(14);
	bag.add(27);
	bag.remove(1);
	bag.printBag();*/
	
	bagTest();
	testAll();
	cout << "Short test passed!\n";
	testAllExtended();
	cout << "Extended test passed!\n";
	system("pause");
}
