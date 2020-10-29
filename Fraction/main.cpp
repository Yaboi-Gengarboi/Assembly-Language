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
	Fraction f3 = f1 - 1;
	cout << f3 << endl;

	return 0;
}