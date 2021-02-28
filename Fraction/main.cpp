// Fraction
// main.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2021-02-27
// Test file for the Fraction class.

#include "Fraction.h"

#include <iostream>
using std::cout;
using std::endl;

void print_fraction(const Fraction& fr)
{
	cout << fr << endl;
}

int main()
{
	Fraction f1(1, 2);
	Fraction f2(2, 3);

	print_fraction(f1);
	print_fraction(f2);

	Fraction f3(f1 + f2);
	print_fraction(f3);
	cout << f3.evaluate() << endl;

	return 0;
}