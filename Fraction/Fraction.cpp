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

long Fraction::numer() const
{
	return _ptr[0];
}

long Fraction::denom() const
{
	return _ptr[1];
}

void Fraction::setNumer(long numer)
{
	set_numer(_ptr, numer);
}

void Fraction::setDenom(long denom)
{
	set_denom(_ptr, denom);
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