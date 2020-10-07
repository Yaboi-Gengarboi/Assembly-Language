// Fraction
// Fraction.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-07

#include "Fraction.h"

#include <ostream>
using std::ostream;

#include <string>
using std::string;
using std::to_string;

Fraction::Fraction()
{
	_ptr = make_empty_fraction();
}

Fraction::Fraction(long numer, long denominator)
{
	_ptr = make_fraction(numer, denominator);
}

Fraction::~Fraction()
{
	delete_fraction(_ptr);
}

string Fraction::toString() const
{
	string str = to_string(_ptr[0]) + " / " + to_string(_ptr[1]);
	return str;
}

ostream& operator << (ostream& os, const Fraction& fr)
{
	os << fr.toString();
	return os;
}