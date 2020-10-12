// Fraction
// main.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-12
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
	Fraction f2(1, 2);

	cout << f1 << endl;
	cout << f2 << endl;

	f1 += f2;
	cout << f1 << endl;

	f1 -= f2;
	cout << f1 << endl;

	return 0;
}