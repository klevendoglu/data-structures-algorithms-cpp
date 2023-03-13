// DataStructuresAlgorithmsCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	Array<int> array{ 10 };
	array.insert(1);
	array.insert(2);
	array.insert(3);
	array.insert(4);
	array.insert(5);
	array.insert(7);
	array.insert(9);
	array.insert(8);
	array.print();
	cout << "index of:" << array.indexOf(6) << endl;
	array.removeAt(3);
	cout << "max of:" << array.max() << endl;
	
	array.insertAt(6, 2);
	array.print();

	int arrToIntersect[] = { 1, 3, 4, 5 };
	int size = sizeof(arrToIntersect) / sizeof(int);
	array.intersect(arrToIntersect, size);

	array.reverse();
	array.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
