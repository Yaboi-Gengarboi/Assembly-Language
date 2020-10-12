// Fraction
// Fraction.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-12
// Source file for Fraction class.

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

Fraction::Fraction(int numer, int denominator)
{
	_ptr = make_fraction(numer, denominator);
}

Fraction::~Fraction()
{
	delete_fraction(_ptr);
}

int Fraction::numer() const
{
	return _ptr[0];
}

int Fraction::denom() const
{
	return _ptr[1];
}

void Fraction::setNumer(int numer)
{
	set_numer(_ptr, numer);
}

void Fraction::setDenom(int denom)
{
	set_denom(_ptr, denom);
}

double Fraction::evaluate() const
{
	return evaluate_fraction(_ptr[0], _ptr[1]);
}

string Fraction::toString() const
{
	string str = to_string(_ptr[0]) + " / " + to_string(_ptr[1]);
	return str;
}

Fraction& Fraction::operator += (const Fraction& f2)
{
	add_fraction(_ptr, f2._ptr);
	return *this;
}

Fraction& Fraction::operator -= (const Fraction& f2)
{
	sub_fraction(_ptr, f2._ptr);
	return *this;
}

ostream& operator << (ostream& os, const Fraction& f)
{
	os << f.toString();
	return os;
}