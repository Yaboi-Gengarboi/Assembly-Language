// Fraction
// Fraction.cpp
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-06

#include "Fraction.h"

Fraction::Fraction(long numer, long denominator)
{
	_ptr = make_fraction(numer, denominator);
}

Fraction::~Fraction()
{
	delete_fraction(_ptr);
}