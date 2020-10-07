// Fraction
// main.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-06

#include "Fraction.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;

void print_fraction(const Fraction& fr)
{
	cout << to_string(fr._ptr[0]) << " / " << to_string(fr._ptr[1]) << endl;
}

int main()
{
	Fraction fr(1, 2);
	print_fraction(fr);

	return 0;
}