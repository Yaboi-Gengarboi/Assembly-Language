// Fraction
// main.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-12-02
// Test file for Fraction class.

#include "Fraction.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Fraction f1(1, 2);
	Fraction f2(1, 2);

	cout << f1 - f2 << endl;

	return 0;
}