// Fraction
// Fraction.h
// Justyn Durnford
// Created on 2020-10-05
// Last updated on 2020-10-07

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <ostream>
#include <string>

extern "C" long* make_empty_fraction();
extern "C" long* make_fraction(long numer, long denom);
extern "C" int   delete_fraction(long* ptr);
extern "C" long* add_fraction(long* fr1, long* fr2);

class Fraction
{
	long* _ptr = nullptr;

	public:

	Fraction();

	Fraction(long numer, long denom);

	~Fraction();

	std::string toString() const;
};

std::ostream& operator << (std::ostream& os, const Fraction& fr);

#endif // FRACTION_H_INCLUDED