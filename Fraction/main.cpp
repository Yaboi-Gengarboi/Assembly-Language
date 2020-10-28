// Fraction
// main.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-28
// Test file for Fraction class.

#include "Fraction.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;

int main()
{
	Fraction f1(1, 2);
	Fraction f2(1, 4);

	cout << "BEFORE SWAP: " << endl;
	cout << f1 << endl;
	cout << f2 << endl;

	f1.swap(f2);

	cout << "AFTER SWAP: " << endl;
	cout << f1 << endl;
	cout << f2 << endl;

	return 0;
}