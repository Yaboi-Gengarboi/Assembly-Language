// Fraction
// main.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-07

#include "Fraction.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;

int main()
{
	Fraction fr(1, 2);
	cout << fr << endl;

	fr.setNumer(2);
	fr.setDenom(3);
	cout << fr << endl;

	return 0;
}